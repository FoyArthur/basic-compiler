#include "lexer.h"

#include <stdexcept>
#include <cctype>
#include <algorithm>

std::vector<std::string> tokenValues = {"PRINT", "IF", "LET", "FOR", "WHILE", "PLUS", "MINUS", "MULT", "DIVIDE", "NUMBER", "STRING", "EQUALS", "QUOTE", "IDENTIFIER", "NEWLINE"};
std::vector<std::string> keywords = {"PRINT", "IF", "LET", "FOR", "WHILE"};

void Lexer::errorMessage(std::string message) {
	std::cout << message << std::endl;
	exit(1);
}

void Lexer::tokenize() {
	getNextChar();
	while(position < (int) input.length()) {
		if(isspace(nextChar) && nextChar != '\n') {
			getNextChar();

		} else if(isalpha(nextChar)) {
			std::string str;
			while(isalnum(nextChar)) {
				str += nextChar;
				int rc = getNextChar();
				if(rc) break;
			}
			auto it = std::find(keywords.begin(), keywords.end(), str);
			if(it != keywords.end()) {
				TokenEnum token = static_cast<TokenEnum>(it-keywords.begin());
				Token t(str, token);
				tokens.push_back(t);
			} else {
				Token t(str, IDENTIFIER);
				tokens.push_back(t);
			}

		} else if(isdigit(nextChar)) {
			std::string num;
			while(isdigit(nextChar)) {
				num += nextChar;
				getNextChar();
			}
			Token t(num, NUMBER);
			tokens.push_back(t);

		} else if(nextChar == '=') {
			Token t("=", EQUALS);
			tokens.push_back(t);
			getNextChar();

		} else if(nextChar == '+') {
			std::string s{nextChar};
			Token t(s, PLUS);
			getNextChar();
			tokens.push_back(t);
		} else if(nextChar == '-') {
			std::string s{nextChar};
			Token t(s, MINUS);
			getNextChar();
			tokens.push_back(t);
		
		} else if(nextChar == '*') {
			std::string s{nextChar};
			Token t(s, MULT);
			getNextChar();
			tokens.push_back(t);

		} else if(nextChar == '/') {
			std::string s{nextChar};
			Token t(s, DIVIDE);
			getNextChar();
			tokens.push_back(t);
		} else if(nextChar == '"') {
			std::string s;
			getNextChar();
			std::string message = "String doesn't end";
			while(nextChar != '"') {
				if(position >= (int) input.length()) {
					errorMessage(message);
				}
				s += nextChar;
				getNextChar();
			}
			Token t(s, STRING);
			tokens.push_back(t);
			getNextChar();
		} else if(nextChar == '\n') {
			std::string s{nextChar};
			Token t(s, NEWLINE);
			getNextChar();
			tokens.push_back(t);
		} else {
			std::string message = "Unknown Character: ";
			message += nextChar;
			errorMessage(message);
			getNextChar();
		}
	}
	return;
}

int Lexer::getNextChar() {
	if(position >= (int) input.length()) return 1;
	nextChar = input[position];		
	position++;
	return 0;
}



