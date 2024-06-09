###########################################################
# Makefile for CS480, Summer 2024
# Assignment #2: XSH
# Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
# Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 
###########################################################
EXEC = dsh
FILES = main.cpp #chatbot.cpp
#HEADERS = chatbot.h 
CC = g++
LFLAGS = -g #-pthread
CFLAGS = -g -c #-pthread
OBJECTS = $(FILES:.cpp=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)
	rm -f *.o

.cpp.o:
	$(CC) $(CFLAGS) $<

# chatbot.o: chatbot.cpp chatbot.h 
# 	$(CC) $(CFLAGS) chatbot.cpp

clean:
	rm -f $(EXEC)
#######################[ EOF: Makefile ]###################