all:
	g++ -Werror -Wpedantic -Wall -g -o basic-compiler main.cpp lexer.cpp parser.cpp emit.cpp
clean:
	rm -rf basic-compiler
