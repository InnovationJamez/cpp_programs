#include "arm.h"

// the constructor
Arm::Arm(){
	
	//initialize all the register vallues to zero
	for(int i = 0; i < 32; i++){
		reg[i] = 0;
		mem[i] = 0;
	}

	openFile();
	dispInst();
	mainLoop();
	dispReg();
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

// iterates through the instruction list and calls other functions
void Arm::mainLoop(){
	for(int i = 0; i < instructionMem.size(); i++){
		std::cout <<  "Count: " << i << std::endl;
		i += reader(instructionMem[i]);
	}
}

// reades a line and reads the instruction
// retures a value for PC to move to 
int Arm::reader(std::string str){
	std::string s;
	bool start;
	std::vector<int> num;
	std::vector<std::string> sList;

	// if B or CBZ end early
	if(wordFinder(str, "B")){
		int num = std::stoi(str.substr(1, str.length() -1 ));
		std::cout << str << std::endl;
		return num;
	}

	start = false;
	if(wordFinder(str, "CBZ")){
		int regVal, num;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == 'x' || str[i] == '#' || str[i] == 'X'){
				start = true;
			}
			else if(str[i] == ','){
				regVal = std::stoi(s);
				break;
			}
			else if(start){
				s.push_back(str[i]);
			}
		}
		num = std::stoi(str.substr(8, str.length() -1 ));
		std::cout << str << std::endl;

		if(regRead(regVal) == 0){
			return num;
		}
		else{
			return 0;
		}
	}

	// check register vallues
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'x' || str[i] == '#' || str[i] == 'X'){
			start = true;
		}
		else if(str[i] == ',' || str[i] == ']'){
			sList.push_back(s);
			s = "";
			start = false;			
		}
		else if(start){
			s.push_back(str[i]);
		}
	}
	sList.push_back(s);

	for(int i = 0; i < 3; i++){
		if(sList[i] == "ZR"){
			num.push_back(0);
		}
		else{
			num.push_back(std::stoi(sList[i]));
		}
	}	

	// find instruction trype and then execute
	if(wordFinder(str, "ADDI")){
		std::cout << str << std::endl;
		regWrite(num[0], regRead(num[1]) + num[2]);
	}
	else if(wordFinder(str, "ADD")){
		std::cout << str << std::endl;
		regWrite(num[0], regRead(num[1]) + regRead(num[2]));
	}
	else if(wordFinder(str, "SUBI")){
		std::cout << str << std::endl;
		regWrite(num[0], regRead(num[1]) - num[2]);
	}
	else if(wordFinder(str, "SUB")){
		std::cout << str << std::endl;
		regWrite(num[0], regRead(num[1]) - regRead(num[2]));
	}
	else if(wordFinder(str, "ORR")){
		std::cout << str << std::endl;
		regWrite(num[0], regRead(num[1])  | regRead(reg[num[2]]));
	}
	else if(wordFinder(str, "AND")){
		std::cout << str << std::endl;
		regWrite(num[0], regRead(num[1])  & regRead(reg[num[2]]));
	}
	else if(wordFinder(str, "LDUR")){
		std::cout << str << std::endl;
		regWrite(num[0], memRead(regRead(num[1]) + num[2]));
	}
	else if(wordFinder(str, "STUR")){
		std::cout << str << std::endl;
		memWrite(regRead(num[1]) + num[2], regRead(num[0]));
	}	

	return 0;
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

//displays the instructions to the console
void Arm::dispInst(){
	int len = instructionMem.size();
	std::cout << "#######ASSEMBLY CODE#######" << std::endl;
	for(int i = 0; i < len; i++){
		std::cout << instructionMem[i] << std::endl;
	}
	std::cout << "###########################" << std::endl;
}

//give it index and returns value in that register
// index values must be 0 - 31 or it will not work 
// and the user will be prompted of the error
int Arm::regRead(int index){
	if(index < 0 || index > 31){
		return 0;
	}
	else{
		int num = reg[index];
		return num;			
	}
}

// give index and value store the value in the register of that index
void Arm::regWrite(int index, int value){
	if(index < 0 || index > 31){
		//ignore
	}
	else{
		reg[index] = value;		
	}
}

//read a value from mempory
//0 - 63
int Arm::memRead(int index){
	if(index < 0 || index > 31){
		return 0;
	}
	else{
		int num = mem[index];
		return num;		
	}
}

// write a value into memory
void Arm::memWrite(int index, int value){
	std::cout << index << " " << value << std::endl;
	if(index < 0 || index > 31){
		//ignore
	}
	else{
		mem[index] = value;		
	}
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