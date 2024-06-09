/*
 ******************* Assignment #2: XSH ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** execute_file.cpp *********************
*/
#include "xsh_shell.h"

void executeFile(const std::string& userInput) {
    std::istringstream cmdStream(userInput);
    std::vector<std::string> args;
    std::string arg;

    // Create vector out of arguments in input
    while (cmdStream >> arg) {
        args.push_back(arg);
    }

    // Check that there is not more than one argument
    if (args.size() != 1) {
        std::cerr << "Error: Invalid number of arguments.\n";
        return;
    }

    // Convert arguments to char* array
    std::vector<char*> argv(args.size() + 1);
    for (size_t i = 0; i < args.size(); ++i) {
        argv[i] = &args[i][0];
    }

    pid_t pid = fork();
    if (pid == 0) { // Child process
        if (execvp(argv[0], argv.data()) < 0) {
            std::perror("execvp");
            std::exit(EXIT_FAILURE);
        }
    } else if (pid > 0) { // Parent process waits for child to finish
        wait(NULL);
    } else { // Error creating fork
        std::perror("fork");
        std::exit(EXIT_FAILURE);
    }
}