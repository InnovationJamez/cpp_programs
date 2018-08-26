#include<iostream>
#include<fstream>

using namespace std;

struct point {
	double x, y;
};

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
	
	double wallWidth = 1 / this->mazeWidth;
	double wallHeight = 1 / this->mazeHeight;
	
	point a;
	point b;
	a.x = 1;
	a.y = 1;
	b.x = 2;
	b.y = 1;
	
	
	if (a.x == b.x)
	{
		myFile << "<line stroke='black' stroke-width='0.01' x1='";
		myFile << wallWidth * a.x;
		myFile << "' y1='";
		myFile << wallHeight * a.y;
		myFile << "' x2='";
		myFile << wallWidth * a.x;
		myFile << "' y2='";
		myFile << wallHeight * a.y - wallHeight;
		myFile << "'/>\n";
	}
	else
	{
		myFile << "<line stroke='black' stroke-width='0.01' x1='";
		myFile << wallWidth * a.x;
		myFile << "' y1='";
		myFile << wallHeight * a.y;
		myFile << "' x2='";
		myFile << wallWidth * a.x - wallWidth;
		myFile << "' y2='";
		myFile << wallHeight * a.y;
		myFile << "'/>\n";
	}

	myFile << "</svg>\n";
	return 0;
}