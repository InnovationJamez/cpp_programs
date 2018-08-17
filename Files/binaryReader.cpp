#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
	char input[32];
	vector<vector<char>>fileVector;
	strcpy(input,"10001011100010111000101110001011");
	fstream file("binFile.bin", ios::binary | ios::in | ios::out | ios::trunc);
	if(!file.is_open())
	{
		std::cout << "error while opening";
	}
	else{
		int length = strlen(input);
		for(int counter = 0; counter<= length; counter++)
		{
		file.put(input[counter]);
		}
		file.seekg(0);
		
		char ch;
		vector<char>tempVector;
		while(file.good())
		{
			
			file.get(ch);
			tempVector.push_back(ch);
			if(tempVector.size() == 32)
			{
				fileVector.push_back(tempVector);
				tempVector.clear();			
			}
		}	
		file.close();
	}
	return 0;
}