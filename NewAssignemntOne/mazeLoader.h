#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<math.h>
#include<cstring>

struct point {
	double x, y;
};

class MazeLoader
{
private:
	point a;
	point b;
	double mazeWidth;
	double mazeHeight;
	double noOfEdges;
	int fileSize;
	double bufferWidth;
	double bufferHeight;
	std::fstream binFile;
	std::ofstream svgFile;
	std::vector<std::string>binFileVector;
public:

	// Enter files names

	void enterBinName(std::string binFileName, 
		std::string svgFileName);

	// check file extemsion

	bool checkVal(int val);

	// check if file is open and valid

	bool checkFileOpen();

	// check file size

	bool checkFileBinSize();

	// start files

	void readLines();

	// binary to decimal

	double binToDecimal(std::string a);

	// Read binFileVector

	void readBinFileVector();

	// Creating a edditing SVG Files

	void beginSVG();
	void lineDefineWidth();
	void lineDefineHeight();
	void drawBorder();
	void addEdge();
	void endSVG();
};

