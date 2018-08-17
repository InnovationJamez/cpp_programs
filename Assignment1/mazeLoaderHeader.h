#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<math.h>

struct point{
	double x, y;
}

class MazeLoader
{
private:
	int mazeWidth;
	int mazeHeight;
	int noOfEdges;
	std::vector<std::vector<char>>binFileVector;


public:
	void startSVG();
	void loadBin();
	bool checkBinFile();
	void startSVG();
	void endSVG();
	
	std::string decimaltobinary (int decimal);
	bool checkIfOpen();
	int binToInt(std::string);
	void readLines(std::vector<int>&binFileVector);
	void setWidth(int*mazeWidth);
	void setHeight(int*mazeHeight);
	void setNumberOfEdges(int*noOfEdges);
	void setEdges(std::vector<int>&binFileVector);
	void addEdge(double boardWidth, boardHeight; point a,b);
};