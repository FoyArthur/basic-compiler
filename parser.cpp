#include "parser.h"
#include "emit.h"

int Parser::parse() {
	assemblyStart();
	parseProgram();
	assemblyEnd(variables);
	return 0;
}

void Parser::error(std::string errorMessage) {
	errorMessage += " at token " + std::to_string(position);
	std::cout << errorMessage << std::endl;
}

void Parser::expect(TokenEnum t) {
	if(tokens[position].token != t) {
		std::string errorMessage = "Expected " + tokenValues[t]; 
		error(errorMessage);
		exit(1);
	}
	position++;
}

void Parser::parseProgram() {
	while(position < (int) tokens.size()) {
		parseStatement();
		if(position == (int) tokens.size()) {
			break;
		} else {
			expect(NEWLINE);
		}
	}
}

//TODO Check for double assignment of variable
void Parser::parseStatement() {
	std::string ident;
	//std::cout << tokens[position].str << std::endl;
	switch(tokens[position].token) {
		case LET:
			expect(LET);
			ident = tokens[position].str;
			expect(IDENTIFIER);
			expect(EQUALS);
			parseExpression();
			variableAssignment(ident);

			// If variable not declared before add it to known variables
			if(!variables.count(ident)) {
				variables.insert(ident);
			}

			break;

		case PRINT:
			expect(PRINT);
			parseExpression();
			print();
			break;

		default:
			std::string message = "Expected Statement";
			std::cout << message << std::endl;
			exit(1);
	}
}

void Parser::parseExpression() {
	parseExpression2();
	while(tokens[position].token == PLUS || tokens[position].token == MINUS) {
		enum TokenEnum token = tokens[position].token;
		position++;
		parseExpression2();
		if(token == PLUS) {
			add();	
		} else {
			subtract();
		}
	}
}

void Parser::parseExpression2() {
	parseExpression3();
	while(tokens[position].token == MULT || tokens[position].token == DIVIDE) {
		enum TokenEnum token = tokens[position].token;
		position++;
		parseExpression3();
		if(token == MULT) {
			multiply();
		} else {
			divide();
		}
	}
}

void Parser::parseExpression3() {
	if(tokens[position].token == PLUS || tokens[position].token == MINUS) position++;
	parseTerm();
}

void Parser::parseTerm() {
	if(tokens[position].token == NUMBER) {
		pushToStackNum(stoi(tokens[position].str));
	} else if(tokens[position].token == IDENTIFIER) {
		pushToStackIdent(tokens[position].str);
	} else {
		std::string s = "Expected NUMBER OR IDENTIFIER";
		std::cout << s << std::endl;
		exit(1);
	}
	position++;
}
