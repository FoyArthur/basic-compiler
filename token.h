#ifndef token_h

#define token_h
#include <string>
#include <vector>

enum TokenEnum {
	PRINT,
	IF,
	LET,
	FOR,
	WHILE,
	PLUS,
	MINUS,
	MULT,
	DIVIDE,
	NUMBER,
	STRING,
	EQUALS,
	QUOTE,
	IDENTIFIER, 
	NEWLINE
};

extern std::vector<std::string> tokenValues;

struct Token {
	std::string str;
	TokenEnum token;
	Token(std::string _str, TokenEnum _token): str(_str), token(_token) {};
}; 



#endif
