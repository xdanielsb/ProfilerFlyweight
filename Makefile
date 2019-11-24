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
ifdef NUM_SOLDIERS
	./main.o "WITH_FLYWEIGHT" $(NUM_SOLDIERS) && ./main.o "WITHOUT_FLYWEIGHT" $(NUM_SOLDIERS)
else
	@echo 'NUM_SOLDIERS is not defined, please check readme.'
endif

clean:
	rm -r *.o

all: compile testu

SHELL := /bin/bash
.DEFAULT_GOAL := all
