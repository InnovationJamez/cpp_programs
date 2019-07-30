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
	std::string filePath = "files/file.txt";
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

	// main loop where everything is executed
	void mainLoop();

	// Instruction fetch
	std::string instructionFetch(int pc);

	// Instruction decode/ register fetch
	std::vector<int> instructionDecode(std::string str);

	// Execute/ address calculation
	void executeInst();

	//Memory access read and write from memory
	int memAccess();

	//Write back
	void writeBack(int regNum, int value);

	// find if a substring exists within a larger string
	bool wordFinder(std::string str, std::string word);
};

