#include <iostream>
#include <string>

std::string encrypt(std::string* input, std::string* key){
	std::string outPut;

	for(int i = 0; i < (*input).length(); i++){
		outPut.push_back((*key)[(*input)[i]]);
	}

	return outPut;
}

int main(){

	char c;
	std::string input = "hello world";
	std::string output = "";
	std::string keyOne = "";
	std::string keyTwo = "";

	for(int i = 0; i < 127; i++){
		c = i;
		keyOne.push_back(c);
	}

	for(int i = 0; i < 127; i++){
		keyTwo.push_back(keyOne[127 - i]);
	}

	output = encrypt(&input, &keyTwo);

	std::cout << "Input: " << input <<std::endl;

	std::cout << "Output: " << output << std::endl;

	return 0;
}