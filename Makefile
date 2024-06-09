###########################################################
# Makefile for CS480, Summer 2024
# Assignment #2: XSH
# Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
# Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 
###########################################################
EXEC = dsh
FILES = main.cpp execute_file.cpp start_process.cpp
HEADERS = xsh_shell.h 
CC = g++
LFLAGS = -g #-pthread
CFLAGS = -g -c #-pthread
OBJECTS = $(FILES:.cpp=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)
	rm -f *.o

.cpp.o:
	$(CC) $(CFLAGS) $<

execute_file.o: execute_file.cpp xsh_shell.h 
	$(CC) $(CFLAGS) execute_file.cpp 

start_file.o: start_process.cpp xsh_shell.h 
	$(CC) $(CFLAGS) start_process.cpp 

clean:
	rm -f *.o $(EXEC)
#######################[ EOF: Makefile ]###################