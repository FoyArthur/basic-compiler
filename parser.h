#include "token.h"
#include <iostream>
#include <stdexcept>
#include <set>

class Parser {
	private:
		std::vector<Token> tokens;
		std::set<std::string> variables;
	public:
		Parser(std::vector<Token> _tokens): tokens(_tokens) {};
		int position = 0;
		int parse();
		void expect(TokenEnum t);
		void error(std::string errorMessage);
		void parseProgram();
		void parseStatement();
		void parseExpression();
		void parseExpression2();
		void parseExpression3();
		void parseTerm();
};

void assemblyStart();
void assemblyEnd();
