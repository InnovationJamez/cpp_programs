#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

#define ADD 	1
#define ADDI 	2
#define SUB 	3
#define SUBI 	4
#define ORR 	5
#define AND 	6
#define LDUR	7
#define STUR	8
#define CBZ		9
#define B 		10


class Arm{
private:
	std::string filePath = "files/test.txt";
	std::vector<std::string> instructionMem;
	int reg[32];
	int mem[32];	
public:
	// the constructor
	Arm();

	// opens file and puts contents into a vector of strings
	void openFile();

	//displays the instructions to the console
	void dispInst();

	// display register values
	void dispReg();

	// display memory values
	void dispMemory();

	// implement hardware sequentially 
	void mainLoop();

	// main loop where pipelining happens
	void pipeLineLoop();

	// Instruction fetch
	std::string instructionFetch(int pc);

	// Instruction decode/ register fetch
	std::vector<int> instructionDecode(std::string str);

	// Execute/ address calculation
	std::vector<int> executeInst(std::vector<int> argList);

	//Memory access read and write from memory
	std::vector<int> memAccess(std::vector<int> argList);

	//Write back
	int writeBack(std::vector<int> argList);

	// find if a substring exists within a larger string
	bool wordFinder(std::string str, std::string word);

	// functions for reading and writting from reg/mem

	int regRead(int index);

	void regWrite(int value, int index);

	int memRead(int index);

	void memWrite(int value, int index);
};

