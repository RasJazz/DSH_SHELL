/*
 ******************* Assignment #2: XSH ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** start_process.cpp ********************
*/
#include "xsh_shell.h"

void startProcess(const std::string& userInput){
    std::vector<std::string> commands;
    std::istringstream stream(userInput);
    std::string command;

    // Split input at pipes
    while (std::getline(stream, command, '|')) {
        commands.push_back(command);
    }

    // Variable to hold number of commands in stream
    // Pipefds: multiple pairs of file descriptors
    int numCommands = commands.size();
    int pipefds[2 * (numCommands - 1)];
    
    // Create pipes by connecting the output command 
    // pipefds[i * 2] to be read by the input pipefds[i * 2 + 1]
    for (int i = 0; i < (numCommands - 1); ++i) {
        if (pipe(pipefds + i * 2) < 0) {
            std::perror("pipe");
            std::exit(EXIT_FAILURE);
        }
    }

    int pid;
    int j = 0;

    for (int i = 0; i < numCommands; ++i) {
        pid = fork();
        
        // Child process
        if (pid == 0) {
            // Redirect input from previous command 
            if (i != 0) {
                if (dup2(pipefds[j - 2], 0) < 0) {
                    std::perror("dup2");
                    std::exit(EXIT_FAILURE);
                }
            }
            // Redirect output to next command
            if (i != numCommands - 1) {
                if (dup2(pipefds[j + 1], 1) < 0){
                    std::perror("dup2");
                    std::exit(EXIT_FAILURE);
                }
            }
            
            // Close all pipe file descriptors
            for (int k = 0; k < 2 * (numCommands - 1); ++k) {
                close(pipefds[k]);
            }

            // Split the command into arguments
            std::istringstream cmdStream(commands[i]);
            std::vector<std::string> args;
            std::string arg;
            while (cmdStream >> arg) {
                args.push_back(arg);
            }

            // Convert arguments to char* array
            std::vector<char*> argv(args.size() + 1);
            for (size_t k = 0; k < args.size(); ++k) {
                argv[k] = &args[k][0];
            }

            // If new process does not replace current process, throw error
            if (execvp(argv[0], argv.data()) < 0) {
                std::perror("execvp");
                std::exit(EXIT_FAILURE);
            }
        } else if (pid < 0) { // Error creating child process
            std::perror("fork");
            std::exit(EXIT_FAILURE);
        }

        j += 2;
    }

    // Close all pipe file descriptors in the parent process
    for (int i = 0; i < 2 * (numCommands - 1); ++i) {
        close(pipefds[i]);
    }

    // Wait for all child processes to finish
    for (int i = 0; i < numCommands; ++i) {
        wait(NULL);
    }
}