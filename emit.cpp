#include "emit.h"

void assemblyStart() {
	printf(".text\n.globl main\n.type main, @function\n\nmain:\n\t");
}

void assemblyEnd(std::set<std::string> v) {
	printf("\n\n//Assembly End\nmov $60, %%rax\nxor %%rdi, %%rdi\nsyscall\n");
	printf("\n.data\n\nformat:\n\t.asciz \"%%d\\n\"\n\n");
	for(auto str: v) {
		printf("%s:\n\t.long 0\n", str.c_str());
	}
}

void pushToStackNum(int i) {
	printf("\n\n// pushing %d to stack\n", i);
	printf("mov $%d, %%rax\n"
			"push %%rax\n", i);
}

void pushToStackIdent(std::string ident) {
	printf("\n\n//pushing %s to stack\n", ident.c_str());
	printf("lea %s(%%rip), %%rax\n"
		"mov (%%rax), %%rbx\n"
		"push %%rbx\n", ident.c_str());
}

void variableAssignment(std::string s) {
	printf("\n\n// assigning %s\n", s.c_str());
	printf("pop %%rbx\n"
			"lea %s(%%rip), %%rax\n"
			"mov %%rbx, (%%rax)\n", s.c_str());
}

std::string intToHexString(int i) {
	std::string output;
	while(i) {
		output += std::to_string(i % 16);
		i/= 16;
	}
	std::reverse(output.begin(), output.end());
	return output;
}

void print() {
	printf("\n\n//Printing\n");
	printf("pop %%rbx\n"
			"push %%rax\n"
			"lea format(%%rip), %%rdi\n"
			"mov %%rbx, %%rsi\n"
			"xor %%eax, %%eax\n"
			"call printf@plt\n"
			"pop %%rax\n");
}

void arithmetic(std::string operation) {
	printf("\n\n//%s\n", operation.c_str());
	printf("pop %%rax\n"
			"pop %%rbx\n"
			"%s %%rax, %%rbx\n"
			"push %%rbx\n", operation.c_str());
}

void add() {
	arithmetic("add");
}

void subtract() {
	arithmetic("sub");
}

void multiply() {
	arithmetic("imul");
};
void divide() {};
