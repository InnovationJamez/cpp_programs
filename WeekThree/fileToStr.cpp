#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
 
int main(int argc, char** argv){
	
	std::ifstream ifs("myFile.txt");
	std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	std::istringstream input;
    input.str(content);
	
	// vector initialization
	std::vector<std::string>myVec;
	
	// Break the string into lines and store into vector
    for (std::string line; std::getline(input, line); ) 
	{
		std::cout << line << std::endl;
		myVec.push_back(line);
    }
	
	for (int i = 0; i < myVec.size(); ++i) 
	{
		std::cout << i << " : " << myVec[i] << std::endl;
	}

	return 0;
}