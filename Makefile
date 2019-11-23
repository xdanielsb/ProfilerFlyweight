#
#    @author SANTOS Daniel, Quintana Gonzalo, Méry Andy
#    @version 1.0 23/11/2019
#

CC = g++ 
CFLAGS = -std=c++11 
CSANIT = -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g 
NAMEFILE = main.cpp

safe-compile:
	$(CC) -DLOCAL $(CFLAGS) $(CSANIT) $(NAMEFILE) -o main.o

compile:
	$(CC) -DLOCAL $(CFLAGS) $(NAMEFILE) -o main.o

testu:
	./main.o "WITH_FLYWEIGHT" && ./main.o "WITHOUT_FLYWEIGHT"

clean:
	rm -r *.o

all: compile testu

SHELL := /bin/bash
.DEFAULT_GOAL := all
