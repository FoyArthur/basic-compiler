#ifndef lexer_h
#define lexer_h

#include <string>
#include <vector>
#include <iostream>

#include "token.h"

class Lexer {
	private:
		int position;
		char nextChar;
		std::string input;

	public:
		std::vector<Token> tokens;
		Lexer(std::string input): position(0), nextChar(' '), input(input) {};
		void tokenize();
		void errorMessage(std::string);
		int getNextChar();
		void printTokens() {
			for(const auto &token: tokens) {
				std::cout << token.str << " " << tokenValues[token.token] << std::endl;
			}
		}
};

#endif
