#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ofstream myFile;
	myFile.open("generatedMaze.svg");
	myFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	myFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	myFile << "<rect width='1' height='1' style='fill: white' />\n";
	
	
	
	myFile << "<line stroke='black' stroke-width='0.01' x1='0' y1='0' x2='1' y2='0'/>\n";
	myFile << "<line stroke='black' stroke-width='0.01' x1='0' y1='1' x2='1' y2='1'/>\n";
	myFile << "<line stroke='black' stroke-width='0.01' x1='0' y1='0' x2='0' y2='1'/>\n";
	myFile << "<line stroke='black' stroke-width='0.01' x1='1' y1='0' x2='1' y2='1'/>\n";
	
	double boardWidth = 4;
	double boardHeight = 4;
	double wallHeight = 1/boardHeight;
	double wallWidth = 1/boardWidth;
	
	double xOne = 2;
	double yOne = 2;
	
	double xTwo = 3;
	double yTwo = 2;
	
	if(yOne == yTwo)
	{
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
	myFile << "</svg>\n";
	return 0;
}