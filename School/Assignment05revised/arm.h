#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

class Arm{
private:
	std::string filePath;
	std::vector<std::string> instructionMem;
	int reg[32];
	int mem[32];	
public:
	// the constructor
	Arm(std::string name);

	// opens file and puts contents into a vector of strings
	void openFile();

	// iterates through the instruction list and calls other functions
	void mainLoop();

	//word finder tells if a word appears in a string
	bool wordFinder(std::string str, std::string word);

	// reades a line and reads the instruction
	// retures a value for PC to move to 
	int reader(std::string str);

	//displays the instructions to the console
	void dispInst();

	//give it index and returns value in that register
	int regRead(int index);

	// give index and value store the value in the register of that index
	void regWrite(int index, int value);

	//read a value from mempory
	int memRead(int index);

	// write a value into memory
	void memWrite(int index, int value);

	// display register values
	void dispReg();

	// display memory values
	void dispMemory();

	// five stages of each insgtruction
	// instruction fetch
	std::string instructionFech(int index);

	// instruction decode and instruction fetch
	std::vector<int> instructionDecode();

};

