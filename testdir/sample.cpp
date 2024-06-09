#include <iostream>
#include <limits>
#include <unistd.h>

void Menu();
void PrintName();

int main(){
    int userInput;
    bool sentinel = true;

    std::cout << "Welcome to the sample program!\n";
    
    while (sentinel) {
        Menu();
        std::cout << "Enter selection: ";
        std::cin >> userInput;

        // Check for invalid input
        while (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number: ";
            std::cin >> userInput;
        }

        if (userInput == 1) {
            PrintName();
        }
        else if (userInput == 2) {
            std::cout << "Quitting program...\n";
	    sleep(1);
            break;
        }
        else {
            std::cout << "\nInvalid menu option.\n";
        }
    }
}

void Menu(){
    std::cout << "-------------Menu------------\n";
    std::cout << "1. Print Name\n";
    std::cout << "2. Quit\n\n";
}

void PrintName(){
    std::string name;

    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "\nHello " << name << "! Returning you to menu\n\n";
    sleep(2);
}
