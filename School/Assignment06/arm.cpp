#include "arm.h"

// the constructor
Arm::Arm(std::string name){

	filePath = "files/" + name + ".txt";
	
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
// main loop where pipelining happens
void Arm::pipeLineLoop(){
	std::string instruction;
	std::vector<int> aluInput;
	std::vector<int> memInput;
	std::vector<int> writeInput;

	bool loopCond = true;
	int pc = 0;

	while(loopCond){
		// write back
		if(writeInput.size() > 0){
			writeBack(writeInput);
			if(writeInput[0] != CBZ && writeInput[0] != B && writeInput[1] == aluInput[2]){
				// modify aluInput for rn
				aluInput.push_back(writeInput[2] && aluInput[0] != LDUR);
			}
			if(writeInput[0] != CBZ && writeInput[0] != B && writeInput[1] == aluInput[3]){
				// modify aluInput for rm
				aluInput.push_back(writeInput[2] && aluInput[0] != LDUR);
			}	
			if(writeInput[0] != CBZ && writeInput[0] != B && writeInput[1] == aluInput[1] && aluInput[0] == STUR){
				aluInput.push_back(writeInput[2]);
			}	
			if(aluInput[0] == CBZ && aluInput[1] == writeInput[1]){
				aluInput.push_back(memInput[2]);
			}	
		}
		// memory access
		if(memInput.size() > 0){
			writeInput = memAccess(memInput);

			// checking for dependancies
			if(writeInput[0] != CBZ && writeInput[0] != B && writeInput[1] == aluInput[2] && aluInput[0] != LDUR){
				// modify aluInput for rn
				aluInput.push_back(writeInput[2]);
			}
			if(writeInput[0] != CBZ && writeInput[0] != B && writeInput[1] == aluInput[3] && aluInput[0] != LDUR){
				// modify aluInput for rm
				aluInput.push_back(writeInput[2]);
			}
			if(writeInput[0] != CBZ && writeInput[0] != B && writeInput[1] == aluInput[1] && aluInput[0] == STUR){
				aluInput.push_back(writeInput[2]);
			}
			if(writeInput[0] != CBZ && writeInput[0] != B && memInput[0] == STUR && memInput[1] == (regRead(aluInput[2]) + aluInput[3])){
				aluInput.push_back(memInput[2]);
			}
			if(aluInput[0] == CBZ && aluInput[1] == writeInput[1]){
				aluInput.push_back(memInput[2]);
			}
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

			for(int i = 0; i < aluInput.size(); i++){
				std::cout << aluInput[i] << " ";
			}
			std::cout << std::endl;
		}
		else{
			aluInput.clear();
		}

		// instruction fetch
		instruction = instructionFetch(pc);
		std::cout << instruction << std::endl;

		if(pc > instructionMem.size() && writeInput.size() == 0){
			loopCond = false;
		}

		if(memInput.size() > 0 && memInput[0] == 10){
			pc+=memInput[1];
		}
		else if(memInput.size() > 0 && memInput[0] == 9 && regRead(memInput[1]) == 0){
			pc+=memInput[2];
		}
		else{
			pc++;
		}
	}

	std::cout << "clock cycles: " << pc << std::endl;
	std::cout << "instruction count: " << instructionMem.size() << std::endl;
	std::cout << "CPI: " << ((double)pc/instructionMem.size()) << std::endl;
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

	// if B type instruction 
	if(wordFinder(str, "B") && !(wordFinder(str, "SUB") || wordFinder(str, "SUBI"))){
		// push instruction type
		regValues.push_back(B);
		// push inst value
		regValues.push_back(std::stoi(str.substr(1, str.length() -1 )));
		// return value
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
	int valOne, valTwo;

	if(argList.size() > 4){
		valOne = argList[4];
	}
	else if(argList[0] == B){
		valOne = argList[1];
	}
	else if(argList[0] == CBZ){
		if(argList.size() > 3){
			valOne = regRead(argList[3]);
		}
		else{
			valOne = regRead(argList[1]);		
		}

	}
	else if(argList[0] == STUR){
		valOne = regRead(argList[1]);
	}
	else if(argList[0] == LDUR){
		valOne = memRead(regRead(argList[2] + argList[3]));
	}
	else{
		valOne = regRead(argList[2]);
	}

	if(argList.size() > 5){
		valTwo = argList[5];
	}
	else if(argList[0] == SUBI || argList[0] == ADDI){
		valTwo = argList[3];
	}
	else if(argList[0] == LDUR || argList[0] == STUR){
		valTwo = regRead(argList[2]);
	}
	else{
		valTwo = regRead(argList[3]);
	}
	
	switch(argList[0]){
		case ADD:
			nextInst.push_back(ADD);
			nextInst.push_back(argList[1]);
			nextInst.push_back(valOne + valTwo);
			break;
		case ADDI:
			nextInst.push_back(ADDI);
			nextInst.push_back(argList[1]);
			nextInst.push_back(valOne + valTwo);
			break;
		case SUB:
			nextInst.push_back(SUB);
			nextInst.push_back(argList[1]);
			nextInst.push_back(valOne - valTwo);
			break;
		case SUBI:
			nextInst.push_back(SUBI);
			nextInst.push_back(argList[1]);
			nextInst.push_back(valOne - valTwo);
			break;	
		case ORR:
			nextInst.push_back(ORR);
			nextInst.push_back(argList[1]);
			nextInst.push_back(valOne | valTwo);			
			break;
		case AND:
			nextInst.push_back(AND);
			nextInst.push_back(argList[1]);
			nextInst.push_back(valOne & valTwo);
			break;
		case LDUR:
			nextInst.push_back(LDUR);
			nextInst.push_back(valOne);
			nextInst.push_back(argList[1]);		
			break;
		case STUR:
			nextInst.push_back(STUR);
			nextInst.push_back(valTwo + argList[3]);
			nextInst.push_back(valOne);
			break;
		case B:
			nextInst.push_back(B);
			nextInst.push_back(argList[1]);
			break;
		case CBZ:
			nextInst.push_back(CBZ);
			nextInst.push_back(valOne);
			nextInst.push_back(argList[2]);
			break;
		default: 
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
			nextArg.push_back(argList[1]);
			break;
		case STUR:
			memWrite(argList[1], argList[2]);
			nextArg = argList;
			break;
		default:
			break;
	}
	return nextArg;
}

//Write back
void Arm::writeBack(std::vector<int> argList){
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
		case STUR:
			// do nothing
			break;
		case LDUR:
			regWrite(argList[1], argList[2]);
			break;
		default:
			break;
	}
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
		slice = str.substr(i, wordLen);
		if(slice == word){
			return true;
		}
	}
	return false;
}