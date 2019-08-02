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
	pipeLineLoop();
	//mainLoop();
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
	std::cout << "#################################REGISTERS####################################" << std::endl;
	for(int i = 0; i < 32; i+=4){
		std::cout << (i<10?"0":"")   << i     << ": " << reg[i]   << "\t\t|\t";
		std::cout << (i+1<10?"0":"") << i + 1 << ": " << reg[i+1] << "\t\t|\t";
		std::cout << (i+2<10?"0":"") << i + 2 << ": " << reg[i+2] << "\t\t|\t";
		std::cout << (i+3<10?"0":"") << i + 3 << ": " << reg[i+3] << std::endl;
	}
}

// display memory values
void Arm::dispMemory(){
	std::cout << "#################################MEMORY#######################################" << std::endl;
	for(int i = 0; i < 32; i+=4){
		std::cout << (i<10?"0":"")   << i     << ": " << mem[i]   << "\t\t|\t";
		std::cout << (i+1<10?"0":"") << i + 1 << ": " << mem[i+1] << "\t\t|\t";
		std::cout << (i+2<10?"0":"") << i + 2 << ": " << mem[i+2] << "\t\t|\t";
		std::cout << (i+3<10?"0":"") << i + 3 << ": " << mem[i+3] << std::endl;
	}
}

// main loop where everything is executed
// this function exists so I can test the parts
// before i implement pipelining
void Arm::mainLoop(){

	std::string instruction;
	std::vector<int> aluInput;
	std::vector<int> memInput;
	std::vector<int> writeInput;

	int inLen = instructionMem.size();

	for(int pc = 0; pc < inLen; pc++){
		// instruction fetch
		instruction = instructionFetch(pc);	
		std::cout << instruction << std::endl;

		// instruction decode
		if(instruction != ""){
			aluInput = instructionDecode(instruction);
		}
		for(int i = 0; i < aluInput.size(); i++){
			std::cout << aluInput[i] << " ";
		}
		std::cout << std::endl;

		// execute instruction
		if(aluInput.size() > 0){
			memInput = executeInst(aluInput);
		}
		for(int i = 0; i < memInput.size(); i++){
			std::cout << memInput[i] << " ";
		}
		std::cout << std::endl;

		// memory access
		if(memInput.size() > 0){
			writeInput = memAccess(memInput);
		}
		for(int i = 0; i < writeInput.size(); i++){
			std::cout << writeInput[i] << " ";
		}
		std::cout << std::endl;

		// write back
		if(writeInput.size() > 0){
			pc += writeBack(writeInput);			
		}
	}

}

// main loop where pipelining happens
void Arm::pipeLineLoop(){
	std::string instruction;
	std::vector<int> aluInput;
	std::vector<int> memInput;
	std::vector<int> writeInput;

	int inLen = instructionMem.size();

	for(int pc = 0; pc < inLen + 5; pc++){
		// write back
		if(writeInput.size() > 0){
			pc += writeBack(writeInput);			
		}
		// memory access
		if(memInput.size() > 0){
			writeInput = memAccess(memInput);
		}
		else{
			writeInput.clear();
		}
		// execute instruction
		if(aluInput.size() > 0){
			memInput = executeInst(aluInput);
		}
		else{
			memInput.clear();
		}
		// instruction decode
		if(instruction != ""){
			aluInput = instructionDecode(instruction);
		}
		else{
			aluInput.clear();
		}

		// instruction fetch
		instruction = instructionFetch(pc);
	}
}

// Instruction fetch
std::string Arm::instructionFetch(int pc){
	if(pc < instructionMem.size()){
		return instructionMem[pc];
	}
	else{
		return "";
	}
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

// Execute/ address calculation
std::vector<int> Arm::executeInst(std::vector<int> argList){
	std::vector<int> nextInst;
	switch(argList[0]){
		case ADD:
			nextInst.push_back(ADD);
			nextInst.push_back(argList[1]);
			nextInst.push_back(reg[argList[2]] + reg[argList[3]]);
			break;
		case ADDI:
			nextInst.push_back(ADDI);
			nextInst.push_back(argList[1]);
			nextInst.push_back(reg[argList[2]] + argList[3]);
			break;
		case SUB:
			nextInst.push_back(SUB);
			nextInst.push_back(argList[1]);
			nextInst.push_back(reg[argList[2]] - reg[argList[3]]);
			break;
		case SUBI:
			nextInst.push_back(SUBI);
			nextInst.push_back(argList[1]);
			nextInst.push_back(reg[argList[2]] - argList[3]);
			break;	
		case ORR:
			nextInst.push_back(ORR);
			nextInst.push_back(argList[1]);
			nextInst.push_back(regRead(argList[2]) | regRead(argList[3]));			
			break;
		case AND:
			nextInst.push_back(AND);
			nextInst.push_back(argList[1]);
			nextInst.push_back(regRead(argList[2]) & regRead(argList[3]));
			break;
		case LDUR:
			nextInst.push_back(LDUR);
			nextInst.push_back(regRead(argList[2]) + argList[3]);
			nextInst.push_back(argList[1]);			
			break;
		case STUR:
			nextInst.push_back(STUR);
			nextInst.push_back(regRead(argList[2]) + argList[3]);
			nextInst.push_back(regRead(argList[1]));
			break;
		case B:
			nextInst.push_back(B);
			nextInst.push_back(argList[1]);
			break;
		case CBZ:
			nextInst.push_back(CBZ);
			nextInst.push_back(argList[1]);
			nextInst.push_back(argList[2]);
			break;
		default:
			std::cout << "Error Invalid Instruction" << std::endl; 
			break;
	}
	return nextInst;
}

//Memory access read and write from memory
std::vector<int> Arm::memAccess(std::vector<int> argList){
	std::vector<int> nextArg;
	switch(argList[0]){
		case ADD:
		case ADDI:
		case SUB:
		case SUBI:
		case CBZ:
		case B:
		case AND:
		case ORR:
			nextArg = argList;
			break;
		case LDUR:
			nextArg.push_back(LDUR);
			nextArg.push_back(argList[2]);
			nextArg.push_back(memRead(argList[1]));
			break;
		case STUR:
			memWrite(argList[1], argList[2]);
			break;
		default:
			std::cout << "Error Invalid Instruction" << std::endl;
			break;
	}
	return nextArg;
}

//Write back
int Arm::writeBack(std::vector<int> argList){
	switch(argList[0]){
		case ADD:
			regWrite(argList[1], argList[2]);
			break;
		case ADDI:
			regWrite(argList[1], argList[2]);
			break;
		case SUB:
			regWrite(argList[1], argList[2]);
			break;
		case SUBI:
			regWrite(argList[1], argList[2]);
			break;
		case AND:
			regWrite(argList[1], argList[2]);
			break;
		case ORR:
			regWrite(argList[1], argList[2]);
			break;
		case LDUR:
			regWrite(argList[1], argList[2]);
			break;
		case B:
			return argList[1];
			break;
		case CBZ:
			if(argList[1] == 0){
				return argList[2];
			}
			else{
				return 0;			
			}
			break;
		default:
			break;
	}
	return 0;
} 

// functions for reading and writting from reg/mem

int Arm::regRead(int index){
	if(index >= 0 && index < 32){
		return reg[index];
	}
	else{
		return 0;
	}
}

void Arm::regWrite(int index, int value){
	if(index >= 0 && index < 32){
		reg[index] = value;
	}
	else{

	}
}

int Arm::memRead(int index){
	if(index >= 0 && index < 32){
		return mem[index];
	}
	else{
		return 0;
	}
}

void Arm::memWrite(int index, int value){
	if(index >= 0 && index < 32){
		mem[index] = value;
	}
	else{

	}
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