#include <iostream>
#include "unistd.h"
#include <cassert>
#include <fstream>
#include <string>
#include <memory>

#include "lexer.h"
#include "parser.h"

#define OPTIONS "i:p"

int getInput(char *fileName, std::string &contents) {
	std::ifstream inf{fileName};

	if(!inf) {
		std::cerr << "Error opening File\n";
		exit(1);
		return 1;
	}

	std::string buffer;

	while(getline(inf, buffer)) {
		contents += buffer + '\n';
	}
	return 0;
}

void printUsage(char **argv) {
	fprintf(stderr, "USAGE: %s -p [-i infile]\n", argv[0]); 
}

int main(int argc, char **argv) {
	int opt = 0;
	int printTokens = 0;

	std::string contents;
	while((opt = getopt(argc, argv, OPTIONS)) != -1) {
		switch(opt) {
			case 'i':
				getInput(optarg, contents);
				break;

			case 'p':
				printTokens = 1;
				break;

			default:
				printUsage(argv);
				return 1;
		}
	}

	std::unique_ptr<Lexer> lexer = std::make_unique<Lexer>(contents);
	lexer->tokenize();

	if(printTokens) {
		lexer->printTokens();
		return 0;
	}

	std::cout << std::endl; 

	std::unique_ptr<Parser> parser = std::make_unique<Parser>(lexer->tokens);
	int rc = parser->parse();
	assert(rc == 0);
	return 0;
}
