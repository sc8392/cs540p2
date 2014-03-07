CC = g++
FLAGS = -std=c++11 -Wall -Wextra -pedantic -g -O0 -Werror

all: map.cpp map.hpp
	$(CC) $(FLAGS) map.cpp -o main