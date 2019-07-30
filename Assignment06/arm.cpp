#include "arm.h"

// the constructor
Arm::Arm(){
	
	//initialize all the register vallues to zero
	for(int i = 0; i < 32; i++){
		reg[i] = 0;
		mem[i] = 0;
	}

	// read file into vector of strings
	openFile();
	// display the instructions
	dispInst();
	// do stuff
	mainLoop();
	// display the register values
	dispReg();
	// display the memory values
	dispMemory();
}

// opens file and puts contents into a vector of strings
void Arm::openFile(){
	std::fstream fObject(filePath, std::fstream::in);
	std::string line;

	if(fObject.is_open()){
		std::cout << "\nFILE OPENED SUCCSESSFULLY!\n" << std::endl;

		while(std::getline(fObject, line)){
			instructionMem.push_back(line);
		}

	}
	else{
		std::cout << "Failed to open the file" << std::endl;
	}
}

//displays the instructions to the console
void Arm::dispInst(){
	int len = instructionMem.size();
	std::cout << "#######ASSEMBLY CODE#######" << std::endl;
	for(int i = 0; i < len; i++){
		std::cout << instructionMem[i] << std::endl;
	}
	std::cout << "###########################" << std::endl;
}

// display register values
void Arm::dispReg(){
	std::cout << "########REGISTERS###########" << std::endl;
	for(int i = 0; i < 32; i+=4){
		std::cout << i     << ": " << reg[i] << " | ";
		std::cout << i + 1 << ": " << reg[i+1] << " | ";
		std::cout << i + 2 << ": " << reg[i+2] << " | ";
		std::cout << i + 3 << ": " << reg[i+3] << std::endl;
	}
}

// display memory values
void Arm::dispMemory(){
	std::cout << "########MEMORY###########" << std::endl;
	for(int i = 0; i < 32; i+=4){
		std::cout << i     << ": " << mem[i] << " | ";
		std::cout << i + 1 << ": " << mem[i+1] << " | ";
		std::cout << i + 2 << ": " << mem[i+2] << " | ";
		std::cout << i + 3 << ": " << mem[i+3] << std::endl;
	}
}

// main loop where everything is executed
void Arm::mainLoop(){
	int pc = 0;
	bool loopCond = true;
	std::vector<int> aluInput;
	std::string instruction;

	// write back 

	// memory access

	// execute instruction
	if(aluInput.size() > 0){
		// execute instructions
	}

	// instruction decode
	if(instruction != ""){
		aluInput = instructionDecode(instruction);
	}

	// instruction fetch
	instruction = instructionFetch(pc);

}

// Instruction fetch
std::string Arm::instructionFetch(int pc){
	return instructionMem[pc];
}

// Instruction decode/ register fetch
std::vector<int> Arm::instructionDecode(std::string str){
	std::vector<int> regValues;
	std::vector<std::string> sList;
	std::string temp;
	bool start = false;

	// if B type instruction 
	if(wordFinder(str, "B")){
		// push instruction type
		regValues.push_back(B);
		// push inst value
		regValues.push_back(std::stoi(str.substr(1, str.length() -1 )));
		// return value
		return regValues;
	}

	// if CBZ type instruction
	if(wordFinder(str, "CBZ")){

		// push inst type
		regValues.push_back(CBZ);

		// find register value
		for(int i = 0; i < str.length(); i++){
			if(str[i] == 'x' || str[i] == '#' || str[i] == 'X'){
				start = true;
			}
			else if(str[i] == ','){
				regValues.push_back(std::stoi(temp));
				break;
			}
			else if(start){
				temp.push_back(str[i]);
			}
		}

		// push other value
		regValues.push_back(std::stoi(str.substr(8, str.length()-1)));
		return regValues;
	}

	// determine the type of instruction
	if(wordFinder(str, "ADDI")){
		regValues.push_back(ADDI);
	}
	else if(wordFinder(str, "ADD")){
		regValues.push_back(ADD);
	}
	else if(wordFinder(str, "SUBI")){
		regValues.push_back(SUBI);
	}
	else if(wordFinder(str, "SUB")){
		regValues.push_back(SUB);
	}
	else if(wordFinder(str, "ORR")){
		regValues.push_back(ORR);
	}
	else if(wordFinder(str, "AND")){
		regValues.push_back(AND);
	}
	else if(wordFinder(str, "LDUR")){
		regValues.push_back(LDUR);
	}
	else if(wordFinder(str, "STUR")){
		regValues.push_back(STUR);
	}

	// check register vallues
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'x' || str[i] == '#' || str[i] == 'X'){
			start = true;
		}
		else if(str[i] == ',' || str[i] == ']'){
			sList.push_back(temp);
			temp = "";
			start = false;			
		}
		else if(start){
			temp.push_back(str[i]);
		}
	}
	sList.push_back(temp);


	for(int i = 0; i < 3; i++){
		if(sList[i] == "ZR"){
			regValues.push_back(0);
		}
		else{
			regValues.push_back(std::stoi(sList[i]));
		}
	}

	return regValues;

}
























//word finder tells if a word appears in a string
bool Arm::wordFinder(std::string str, std::string word){
	int wordLen = word.length();
	int strLen = str.length();
	std::string slice;

	for(int i = 0; i < strLen - wordLen; i++){
		slice = str.substr(i, i + wordLen);
		if(slice == word){
			return true;
		}
	}
	return false;
}