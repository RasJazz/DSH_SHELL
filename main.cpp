// Makefile for CS480, Summer 2024
// Assignment #2: XSH
// Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
// Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 
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
            std::cout << "PIPING HOT\n";
        }
        // else, user would like to execute a file and shell will search for it
        else {
            std::cout << "You input a filename!\n";
        }
    }
}