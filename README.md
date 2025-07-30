# DSH SHELL

---

Created By: Aeron Flores and Jasmine Rasmussen
CS480, Summer 2024 
Assignment 2, README

### Overview

---

DSH is a shell program that has two built-in functions:
- **Start Process**
	- lets users create processes that can be chained using pipes to communicate with each other
- **Run Program**
	- lets users search for a file and run it in the shell if it is an executable

### Files Included

---

Files/Folders included in `a2.zip`:
- `README.md`: Details on the program and how to run it
- `Makefile`: Makefile used to compile the `dsh` executable
- `xsh_shell.h`: Header file for the shell
- `main.cpp`: Main source file that takes user input and calls appropriate function
- `execute_file.cpp`: Source file for executeFile function. This file houses the logic for opening files using the shell
- `start_process.cpp`: Source file for startProcess function. This file houses the logic for chaining shell commands together and establishes a pipe between them
- `testdir`: Test directory that houses a sample program to run in shell
- `testdir/sample.cpp`: Source file for sample program that lets users enter their name or quit

### Compile instructions

---

##### Requirements:

To compile the program, **G++ v.4.8.5** (or a similar compiler) that compiles **C++11** is needed.

###### File Installation
1. Download `a2.zip` and extract the files to a directory of your choice.
2. Once finished, open your terminal and navigate to `a2`.
	To navigate to the directory: 
	- Windows Command Prompt (cmd)/PowerShell:  `cd Drive:\path\to\directory\a2`
	- MacOS: `cd /path/to/directory/a2`
	- Linux/UNIX: `cd /path/to/directory/a2`
3. Run command `make` to create the executable `dsh`.

### Run Program

---

Program `dsh` is ready to be used! Run the program using the following commands:
- Windows Command Prompt (cmd): `dsh`
- Windows PowerShell: `.\dsh`
- Linux/UNIX/MacOS: `dsh`

***NOTE:*** Command `make clean` will remove any generated object files and executables.

### How to use shell

---

##### Chaining Processes Together

Separate shell commands using a pipe
- ex.

```
cssc4427% ls -li | sort -fi
 2523 -rw-r--r-- 1 jazzy jazzy   1236 Jun  8 20:40 execute_file.cpp
11272 -rw-r--r-- 1 jazzy jazzy   1193 Jun  8 20:40 main.cpp
11276 -rw-r--r-- 1 jazzy jazzy    834 Jun  8 19:55 Makefile
20047 -rw-r--r-- 1 jazzy jazzy   1993 Jun  8 22:49 README.md
21512 -rw-r--r-- 1 jazzy jazzy   2775 Jun  8 20:57 start_process.cpp
21517 -rw-r--r-- 1 jazzy jazzy    594 Jun  8 20:40 xsh_shell.h
35141 drwxr-xr-x 2 jazzy jazzy   4096 Jun  8 22:46 testdir
35148 -rwxr-xr-x 1 jazzy jazzy 246296 Jun  8 22:59 dsh
total 272
```

##### Opening files

To open an executable, type in the path or file name to run it.
- ex.

```
cssc4427% ./testdir/sample_program
Welcome to the sample program!
-------------Menu------------
1. Print Name
2. Quit

Enter selection: 2
Quitting program...
cssc4427%
```

##### Exiting Shell

To exit the shell, run the command `exit`.
- ex. `cssc4427% exit`

### Design Decisions

---

###### Modular Design

The project is organized into multiple source files (`main.cpp`, `execute_file.cpp`, and `start_process.cpp`), each handling specific parts of the shell functionality. This modular design helps with code readability, maintainability, and the facilitation of easier debugging and testing.

###### Process Management and Piping

The shell is made to handle multiple processes by using `fork()` to create child processes and supports piping between them by using `pipe()`. This design allows the shell to execute complex command sequences that involve pipes, which closely imitates the behavior of traditional UNIX-like shells.

###### Input Handling, Command Execution, and File Execution

The shell reads user input in a loop, checking for specific commands such as `exit` to terminate the shell. It also parses user input to detect pipes and decides whether to execute a single command or a series of piped commands. Finally, it supports searching and executing an executable file. This decision ensures that the shell can handle a variety of input scenarios efficiently and effectively, properly process user-designated commands, and allow programs to be run by the user.

### Other Features

---

- **Sample Program:** `sample.cpp` creates executable when `make` command run to test functionality of opening executable files

### Known Bugs

---

- **Edge Cases in Piping:** Some edge cases might have a situation where piping might not work as expected, particularly with complex command sequences. This is an area that can be improved.

- **Race Conditions:** Occasionally, when under high load, race conditions may occur when multiple threads try to write to the file simultaneously. 


### Lessons Learned

---

- **Importance of Synchronization:** One of the key takeaways from this project was understanding the crucial role of synchronization in concurrent programming. The proper use of semaphores is capable of significantly reducing the risk of data corruption.

- **Debugging Multithreaded Applications:** We learned that is it challenging to debug multithreaded applications. Tools such as VScode helped in finding and resolving issues related to thread behavior and memory management.

- **Shell Programming Fundamentals:** Implementing a shell from scratch provided lots of information about how shells work, which includes command parsing, process management, and inter-process communication.

- **Effective Collaboration and Teamwork:** Working in pairs showed the need for clear communication and division of tasks. We learned that regular code reviews and pair programming sessions on the Discord app can greatly enhance code quality and team productivity.


### Code Creation

---

**Jasmine:**
- `main.cpp`
	- 1-34
- `execute_file.cpp`
	- 1-10
	- 31-32
	- 38
	- 41
- `start_process.cpp`
	- 1-10
- `xsh_shell.h`
	- 1-20
- `sample.cpp`
	- 1-54

**Aeron:**
- `execute_file.cpp`
	- 11-30
	- 33-37
	- 39-40
	- 42-45
- `start_process.cpp`
	- 11-94
