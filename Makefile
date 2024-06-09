###########################################################
# Makefile for CS480, Summer 2024
# Assignment #2: XSH
# Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
# Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 
###########################################################
# Shell Program
DSH_SHELL = dsh
FILES = main.cpp execute_file.cpp start_process.cpp
HEADERS = xsh_shell.h 
CC = g++
LFLAGS = -g
CFLAGS = -g -c
OBJECTS = $(FILES:.cpp=.o)

# Sample Program
EXEC = sample_program
SAMPLE = testdir/sample.cpp
SAMPLE_OUTPUT = testdir/$(EXEC)

# Compile and create dsh executable file
$(DSH_SHELL):$(OBJECTS)
	$(CC) $(LFLAGS) -o $(DSH_SHELL) $(OBJECTS)
	rm -f *.o

# Compile and create sample_program executable in testdir directory
$(SAMPLE_OUTPUT): $(OBJECTS) $(SAMPLE)
	$(CC) $(LFLAGS) -o $(SAMPLE_OUTPUT) $(OBJECTS) $(SAMPLE)
	rm -f *.o

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
	rm -f *.o $(DSH_SHELL)
#######################[ EOF: Makefile ]###################