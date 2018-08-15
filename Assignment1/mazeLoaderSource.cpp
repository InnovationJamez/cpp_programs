#include"mazeLoaderHeader.h"

void loadBin()
{
	fstream binFile("binFile.bin",ios::binary | ios::in | ios::out | ios::trunc )
}

void startSVG()
{
	ofstream svgFile("generatedMaze.svg");
}

bool checkIfOpen()
{
	bool tempBool;
	if(!file.is_open())
	{
		tempBool == false;
	}else
	{
		tempBool == true;
	}
	return tempBool;
}

int binToInt(std::binString)
{
	int tempInt = 0;
	for(int i = 0; i < binString.size();++i)
	{
		tempInt += pow(2,i);
	}
	return tempInt;
}

void startSVG()
{
	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	svgFile << "<rect width='1' height='1' style='fill: white' />\n";
}

void addEdge(double xOne, yOne, xTwo, yTwo, boardWidth, boardHeight)
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

void endSVG()
{
	myFile << "</svg>\n";
	myFile.close();
}

void readLines(std::vector<int>&binFileVector)
{
	binFile.seekg(0);
	for()
	{
		file.read((char*)&)
	}
	
	
}

int main()
{
	
	
}
