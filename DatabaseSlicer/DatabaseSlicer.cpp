#include "DatabaseSlicer.h"

// fload file into vector of strings
bool loadFile(std::string filePath, list* fileVector){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::in);
	std::string line;
	if(fileObject->is_open()){
		while(getline((*fileObject), line)){
			int lineLength = line.length();
			for(int i = 0; i < lineLength;i++){
				if(line[i] > 96 && line[i] < 123){
					line[i] -= 32;
				}
			}
			(*fileVector).push_back(line);
		}
		delete fileObject;
		return true;
	}
	else{
		std::cout << "\"" << filePath << "\" filed to open" << std::endl;
		delete fileObject;
		return false;
	}
}

// load database
bool loadDatabase(std::string filePath, list* fileVector){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::in);
	std::string temp = "";
	std::string line;
	char firstChar;
	char lastLineLastChar;
	if(fileObject->is_open()){
		while(getline((*fileObject), line)){
			firstChar = line[0];
			lastLineLastChar = temp[temp.length() - 1];
			// when the last char is a '.' and the fist char of the next line is a number then 
			// this is going from one index to another
			if(firstChar > 47 && firstChar < 58 && lastLineLastChar == '.'){
				(*fileVector).push_back(temp);
				temp="";
				temp+=line;
			}
			else{
				temp+=line;
			}
		}
		delete fileObject;
		return true;
	}
	else{
		std::cout << "\"" << filePath << "\" filed to open" << std::endl;
		delete fileObject;
		return false;
	}	
}

// loop through the food database, find key words, remove non important ingreediants
void loopThroughDatabase(list* fdv, list* sList){
	int length = (*fdv).size();
	for(int i = 0; i < length; i++){
		// slice string into array
		list line = sliceString((*fdv)[i]);
		// convert to a string
		int lineLen = line.size();
		// store temporary sting
		std::string temp = "";
		// read through formated line and turn back to string
		temp+=(line.size() > 0) ? line[0] + ";" : "";
		temp+=(line.size() > 1) ? line[1] + ";" : "";
		// check if sugars have been found
		bool sugar = false;
		for(int j = 2; j < lineLen; j++){
			if(checkIngredient(line[j], sList)){
				if(!sugar){
					temp+=line[j];
				}
				else{
					temp+="," + line[j];
				}
				sugar = true;
			}
		}
		temp+=(sugar) ? "" : "none";
		(*fdv)[i] = temp;
	}
}

// slice the data into three pieces and then find the subparts
list sliceString(std::string s){
	std::string temp = "";
	list out;
	int len = s.length();
	// find the upc number
	for(int i = 0; i < len; i++){
		if(s[i] == '\t'){
			out.push_back(temp);
			temp = "";
		}
		else if(s[i] != '"' && !(s[i] == ' ' && temp.length() == 0)){
			temp+=s[i];
		}
	}

	// break up the ingrediant list
	std::string tempStr = temp;
	temp = "";
	len = tempStr.length();

	for(int i = 0; i < len; i++){
		if((tempStr[i] == ',' || tempStr[i] == '(' || tempStr[i] == ')') && temp.length() > 0){
			out.push_back(temp);
			temp="";
		}
		else if(!(tempStr[i] == ',' || tempStr[i] == '.' || tempStr[i] == '[' || tempStr[i] == ']') && !(temp.length() == 0 && tempStr[i] == ' ')){
			temp+=tempStr[i];
		}
	}
	out.push_back(temp);

	return out;
}

// stor a vector of strings into a file
void storeFile(std::string filePath, list* fileVector){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::out | std::fstream::trunc);
	(*fileObject) << "UPC;Description;Types of Sugar\n";
	int length = fileVector->size();
	for(int i = 0; i < length; i++){
		(*fileObject) << (*fileVector)[i] << "\n";
	}
	delete fileObject;
}

// check if it is a added sugar
bool checkIngredient(std::string item, list* sugarList){
	int len = sugarList->size();
	for(int i = 0; i < len;i++){
		if(item == (*sugarList)[i]){
			return true;
		}
	}
	return false;
}

// print the contents of a vector
void printVector(list* vec){
	int length = (*vec).size();
	for(int i = 0; i < 20; i++){
		std::cout << "-";
	}
	std::cout << "\n";
	for(int i = 0; i < length; i++){
		std::cout << (*vec)[i] << std::endl;
	}
	for(int i = 0; i < 20; i++){
		std::cout << "-";
	}
	std::cout << "\n";
}