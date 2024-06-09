/*
 ******************* Assignment #2: XSH ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ********************** xsh_shell.h ************************
*/
#ifndef XSH_SHELL
#define XSH_SHELL
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

// Function prototypes for starting processes, file execution
void startProcess(const std::string&);
void executeFile(const std::string&);

#endif