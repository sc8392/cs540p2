CC = g++
FLAGS = -std=c++11 -Wall -Wextra -pedantic -g -O0

all: map.cpp map.hpp BST.cpp BST.h Node.cpp Node.h main.cpp
	$(CC) $(FLAGS) main.cpp -o main

clean:
	rm -f main