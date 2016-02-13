FLAGS=-ansi -pedantic -Wall -Werror

all:
	rm -rf bin
	mkdir bin
	g++ $(FLAGS) src/rshell.cpp -o bin/rshell

rshell:
	rm -rf bin
	mkdir bin
	g++ $(FLAGS) src/rshell.cpp -o bin/rshell

