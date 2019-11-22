CC = g++ 
CFLAGS = -std=c++11 

run:
	$(CC) -DLOCAL $(CFLAGS) -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g main.cpp	&& ./a.out
fast:
	$(CC) -DLOCAL $(CFLAGS)  main.cpp  && ./a.out
