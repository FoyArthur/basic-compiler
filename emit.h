#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

void assemblyStart();
void assemblyEnd(std::set<std::string>);
void arithmetic(std::string operation);
void add();
void subtract();
void multiply();
void divide();
void pushToStackNum(int i);
void pushToStackIdent(std::string ident);
void variableAssignment(std::string s);
void print();
std::string intToHexString(int i);

