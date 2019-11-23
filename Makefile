CC = g++ 
CFLAGS = -std=c++11 
CSANIT = -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g 

compile:
	$(CC) -DLOCAL $(CFLAGS) $(SANIT) launcher.cpp

test:
	./a.out "WITH_FLYWEIGHT" && ./a.out "WITHOUT_FLYWEIGHT"

all:
	$(CC) -DLOCAL $(CFLAGS) $(SANIT) launcher.cpp	&& ./a.out

all-free:
	$(CC) -DLOCAL $(CFLAGS)  launcher.cpp  && ./a.out
