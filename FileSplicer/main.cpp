#include<fstream>
#include<string>
#include<vector>
#include<iostream>

#define list std::vector<std::string>*

void loadFile(std::string filePath, list fileVector);

void removeQuotes(list fileVector);

void writeToOut(list upcName, list sugarList, std::string outPath);

void printVector(list vec);

int main(){
	// file paths
	std::string upcAndNamePath = "other.csv";
	std::string addedSugarsPath = "SugarList.csv";
	std::string outputPath = "output.csv";

	// file vectors

	list upcAndNameVec = new std::vector<std::string>;
	list addedSugarsVec = new std::vector<std::string>;

	loadFile(upcAndNamePath, upcAndNameVec);
	loadFile(addedSugarsPath, addedSugarsVec);

	removeQuotes(upcAndNameVec);

	writeToOut(upcAndNameVec,addedSugarsVec,outputPath);

	delete upcAndNameVec;
	delete addedSugarsVec;

}

// fload file into vector of strings
void loadFile(std::string filePath, std::vector<std::string>* fileVector){
	std::fstream* fileObject = new std::fstream(filePath, std::fstream::in);
	std::string line;
	if(fileObject->is_open()){
		while(getline((*fileObject), line)){
			(*fileVector).push_back(line);
		}
	}
	else{
		std::cout << filePath << " filed to open" << std::endl;
	}

	delete fileObject;
}

// remove quotes from the product names
void removeQuotes(list fileVector){
	int len = fileVector->size();
	std::string temp;
	for(int i = 0; i < len; i++){
		int sLen = (*fileVector)[i].length();
		temp = "";
		for(int j = 0; j < sLen;j++){
			if((*fileVector)[i][j] != '"'){
				temp+=(*fileVector)[i][j];
			}
		}
		(*fileVector)[i]=temp;
	}
}

void writeToOut(list upcName, list sugarList, std::string outPath){
	std::fstream* fileObject = new std::fstream(outPath, std::fstream::out | std::fstream::trunc);
	if(fileObject->is_open()){
		int length = upcName->size();
		for(int i = 0; i < length; i++){
			(*fileObject) << (*upcName)[i] << ";" << (*sugarList)[i] << std::endl;
		}
	}
	else{
		std::cout << outPath << " filed to open" << std::endl;
	}
	delete fileObject;
}

void printVector(list vec){
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