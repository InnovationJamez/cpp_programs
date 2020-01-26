#include "DatabaseSlicer.h"

// fload file into vector of strings
bool loadFile(std::string filePath, list* fileVector){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::in);
	std::string line;
	std::string temp;
	if(fileObject->is_open()){
		while(getline((*fileObject), line)){
			if(line[6] > 47 && line[6] < 58 && line[0] > 47 && line[0] < 58){
				(*fileVector).push_back(temp);
				temp = line;
			}
			else{
				temp += line;
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

// fload in the sugar database while setting all characters to uppercase
bool loadSugarData(std::string filePath, list* fileVector){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::in);
	std::string line;
	int len;
	char c;
	if(fileObject->is_open()){
		while(getline((*fileObject), line)){
			len = line.length();
			for(int i = 0; i < len; i++){
				c = line[i];
				line[i] = (c > 96 && c < 123) ? c - 32 : c;
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

// split the data into its catagories
void splitDataCatagories(list* upc, list* brand, list* desc, list* ingred, list* data){
	int dataLength = (*data).size();
	int stringLen;

	for(int i = 0; i < dataLength; i++){
		// initialize variabkles
		list splitLine;
		stringLen = (*data)[i].length();
		std::string temp = "";

		// split line into parts
		for(int j = 0; j < stringLen; j++){
			if((*data)[i][j] == '\t'){
				splitLine.push_back(temp);
				temp = "";
			}
			else{
				temp += (*data)[i][j];
			}
		}
		splitLine.push_back(temp);

		// put each part in a string
		if(splitLine.size() > 0){
			(*upc).push_back(splitLine[0]);
		}
		else{
			(*upc).push_back("");
		}
		if(splitLine.size() > 1){
			(*brand).push_back(splitLine[1]);
		}
		else{
			(*brand).push_back("");
		}
		if(splitLine.size() > 2){
			(*desc).push_back(splitLine[2]);
		}
		else{
			(*desc).push_back("");
		}
		if(splitLine.size() > 3){
			(*ingred).push_back(splitLine[3]);
		}
		else{
			(*ingred).push_back("");
		}
	}
}

// remove all the non sugars from the ingrediants
void removeNonSugars(list* sugarList, list* ingredList){
	int foodLength = (*ingredList).size();
	(*ingredList)[0] = "Types of Sugar";
	for(int i = 1; i < foodLength; i++){
		list foodList = stringToList((*ingredList)[i]);
		list sugarIngred;

		for(int j = 0; j < foodList.size(); j++){
			if(checkIngredient(foodList[j], sugarList)){
				sugarIngred.push_back(foodList[j]);
			}
		}

		(*ingredList)[i] = listToString(sugarIngred);
	}
}

// take the ingrediant string and return a list of ingrediants
list stringToList(std::string s){
	list foodList;
	std::string temp = "";
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ','){
			foodList.push_back(temp);
			temp="";
		}
		else if(s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && 
				s[i] != '.' && !(temp.length() == 0 && s[i] == ' ')){
			temp+=s[i];
		}
	}

	foodList.push_back(temp);

	return foodList;
}

// take the list and return a string
std::string listToString(list l){
	std::string s;

	if(l.size() == 0){
		return "No Added Sugars";
	}

	s+= l[0];

	for(int i = 1; i < l.size(); i++){
		s+= ',' + l[i];
	}

	return s;
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

// stor a vector of strings into a file
void storeFile(std::string filePath, list* upc, list* name, list* ingred){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::out | std::fstream::trunc);
	int length = upc->size();
	for(int i = 0; i < length; i++){
		(*fileObject) << (*upc)[i] << ";" << (*name)[i] << ";" << (*ingred)[i] << "\n";
	}
	delete fileObject;
}

// combine two columns
void combineColumns(list* brand, list* desc, list* name){
	name->push_back("Name");
	int len = brand->size();
	for(int i = 1; i < len; i++){
		name->push_back((*brand)[i] + " " + (*desc)[i]);
	}
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