#include "arm.h"

void openFile(std::string* s, std::vector<std::string>* v){
	std::fstream fObject(*s, std::fstream::in);
	std::string line;

	if(fObject.is_open()){
		std::cout << "\nFILE OPENED SUCCSESSFULLY!\n" << std::endl;

		while(std::getline(fObject, line)){
			(*v).push_back(line);
		}

	}
	else{
		std::cout << "Failed to open the file" << std::endl;
	}
}

void mainLoop(std::vector<std::string>* v, int* reg, int* mem){
	for(int i = 0; i < (*v).size(); i++){
		i += reader((*v)[i], reg, mem);
	}
}

int reader(std::string str, int* reg, int* mem){
	std::string s;
	bool start;
	std::vector<int> num;
	std::vector<std::string> sList;

	// if B or CBZ end early
	if(wordFinder(str, "B")){
		int num = std::stoi(str.substr(1, str.length() -1 ));
		std::cout << num << std::endl;
		std::cout << str << std::endl;
		return num;
	}

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
		std::cout << regVal << std::endl;
		std::cout << num << std::endl;
		std::cout << str << std::endl;

		if(regRead(regVal, reg)){
			return num;
		}
		else{
			return 0;
		}
		
	}

	// check register vallues
	for(int i = 0; i < str.length(); i++){
		if(s.length() == 2 || str[i] == ',' || str[i] == ']'){
			sList.push_back(s);
			s = "";
			start = false;
		}
		if(start == true){
			s.push_back(str[i]);
		}
		if(str[i] == 'x' || str[i] == '#' || str[i] == 'X'){
			start = true;
		}
		if(i == str.length() - 1){
			sList.push_back(s);
		}
	}

	
	for(int i = 0; i < 3; i++){
		std::cout << sList[i] << std::endl;
		if(sList[i] == "ZR"){
			num.push_back(0);
		}
		else{
			num.push_back(std::stoi(sList[i]));
		}
	}		

	// find instruction trype and then execute
	if(wordFinder(str, "ADD")){
		std::cout << str << std::endl;
		memWrite(regRead(num[1], reg) + regRead(num[2], reg), num[0], reg);
	}
	else if(wordFinder(str, "ADDI")){
		std::cout << str << std::endl;
		memWrite(regRead(num[1], reg) + num[2], num[0], reg);
	}
	else if(wordFinder(str, "SUB")){
		std::cout << str << std::endl;
		memWrite(regRead(num[1], reg) - regRead(num[2], reg), num[0], reg);
	}
	else if(wordFinder(str, "SUBI")){
		std::cout << str << std::endl;
		memWrite(regRead(num[1], reg) - num[2], num[0], reg);
	}
	else if(wordFinder(str, "ORR")){
		std::cout << str << std::endl;
		regWrite(regRead(num[1], reg)  | regRead(reg[num[2]], reg), num[0], reg);
	}
	else if(wordFinder(str, "AND")){
		std::cout << str << std::endl;
		regWrite(regRead(num[1], reg)  & regRead(reg[num[2]], reg), num[0], reg);
	}
	else if(wordFinder(str, "LDUR")){
		std::cout << str << std::endl;
		regWrite(memRead(regRead(num[1], reg) + num[2], reg), num[0], reg);
	}
	else if(wordFinder(str, "STUR")){
		std::cout << str << std::endl;
		memWrite(regRead(num[0], reg), regRead(num[1], reg) + num[2], reg);
	}	

	return 0;
}

//read value from register
int regRead(int ind, int* reg){
	int num = reg[ind];
	return num;
}

// write value into register
void regWrite(int val, int ind, int* reg){
	reg[ind] = val;
}

//read a value from mempory
int memRead(int ind, int* mem){
	int num = mem[ind];
	return num;
}

// write a value into memory
void memWrite(int val, int ind, int* mem){
	mem[ind] = val;
}


bool wordFinder(std::string str, std::string word){
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

//print off the instructions that were loader
void instPrint(std::vector<std::string>* v){
	for(int i = 0; i < (*v).size(); i++){
		std::cout << (*v)[i] << std::endl;
	}	
}