/*
 ******************* Assignment #2: XSH ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ************************ main.cpp *************************
*/
#include "xsh_shell.h"
#include <iostream>

int main(){
    // Runs shell until user indicates they would like to exit
    while(true){
        std::string userInput;
        
        // Output for user to indicate they are in the shell
        // input is being expected
        // userInput waits to collect input from user
        std::cout << "cssc4427% ";
        std::getline(std::cin, userInput);

        // if userInput is exit, exits shell
        if (userInput == "exit") {
            std::cout << "BYEEEEE\n";
            break;
        }
        // if user input contians pipes, creates 2+ processes
        // each process connected to last via pipe
        else if (userInput.find("|") != std::string::npos){
            /* 
                          TO DO:
            - split input at pipes
            - check that correct number of arguments are there
            */
           startProcess(userInput);
        }
        // else, user would like to execute a file and shell will search for it
        else {
            /* 
                          TO DO:
            - error check there isn't more than 1 arg
            */
            executeFile(userInput);
        }
    }
}