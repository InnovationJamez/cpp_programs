#include"mazeLoaderHeader.h"

void MazeLoader::loadBin()
{
	fstream binFile("binFile.bin",ios::binary|ios::in|ios::out|ios::trunc)
}

void MazeLoader::startSVG()
{
	ofstream svgFile("generatedMaze.svg");
}

bool MazeLoader::checkIfOpen()
{
	bool tempBool;
	if(!binFile.is_open())
	{
		tempBool == false;
	}else
	{
		tempBool == true;
	}
	return tempBool;
}

int MazeLoader::binToInt(std::vector<char>binVector)
{
	int tempInt = 0;
	for(int i = 0; i < binVector.size();++i)
	{
		tempInt += pow(2,i);
	}
	return tempInt;
}

string decimaltobinary (int decimal){
	string binary;
	int rem = decimal%2;
	while(rem!==0){
		if(decimal%2==0){
			binary == "0" + binary;
		}
		
		if(decimal%2==1){
			binary == "1" + binary;
		}
		decimal = decimal/2
	}
	
	while(decimal.length()<=32){
		decimal = "0" + decimal;
	}
	
	if(decimal.length()>32){
		std::cout << "Error! Binary value must have less than 32 characters << std::endl;
		break;
	}
}



void MazeLoader::startSVG()
{
	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	svgFile << "<rect width='1' height='1' style='fill: white' />\n";
}

void MazeLoader::addEdge(double boardWidth, boardHeight; point a,b)
{
	if(yOne == yTwo)
	{
		
		double wallHeight = 1/boardHeight;
		double wallWidth = 1/boardWidth;
		myFile << "<line stroke='black' stroke-width='0.01' x1='";
		myFile << wallWidth*xOne;
		myFile << "' y1='";
		myFile << wallHeight*yOne;
		myFile << "' x2='";
		myFile << wallWidth*xOne;
		myFile << "' y2='";
		myFile	<< wallHeight*yOne-wallHeight;
		myFile << "'/>\n";
	}
	else
	{
		myFile << "<line stroke='black' stroke-width='0.01' x1='";
		myFile << wallWidth*xOne;
		myFile << "' y1='";
		myFile << wallHeight*yOne;
		myFile << "' x2='";
		myFile << wallWidth*xOne-wallWidth;
		myFile << "' y2='";
		myFile	<< wallHeight*yOne;
		myFile << "'/>\n";		
	}
}

void MazeLoader::endSVG()
{
	myFile << "</svg>\n";
	myFile.close();
}

void MazeLoader::readLines(std::vector<int>&binFileVector)
{
	for(int counter = 0; counter<= length; counter++)
		{
		binFile.put(input[counter]);
		}
		binFile.seekg(0);
		
		char ch;
		vector<char>tempVector;
		while(binFile.good())
		{
			binFile.get(ch);
			tempVector.push_back(ch);
			if(tempVector.size() == 32)
			{
				fileVector.push_back(tempVector);
				tempVector.clear();			
			}
		}	
		binFile.close();
}

int main()
{
	MazeLoader mazeOne;
	
	
}
