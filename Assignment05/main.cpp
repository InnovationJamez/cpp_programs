#include "arm.h"


int main(){
	std::string filePath = "files/file.txt";
	std::vector<std::string> instructionMem;
	int reg[32];
	int mem[64];

	openFile(&filePath, &instructionMem);
	instPrint(&instructionMem);
	mainLoop(&instructionMem, reg, mem);

	return 0;
}