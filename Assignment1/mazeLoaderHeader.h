#include<iostream>
#include<vector>
#include<>
#include<fstream>
#include<math>

class MazeLoader
{
private:
	int mazeWidth;
	int mazeHeight;
	int noOfEdges;
	std::vector<int>binFileVector;


public:
	void startSVG();
	void loadBin();
	bool checkBinFile();
	void startSVG();
	void endSVG();
	
	
	bool checkIfOpen();
	int binToInt(std::string);
	void readLines(std::vector<int>&binFileVector);
	void setWidth(int*mazeWidth);
	void setHeight(int*mazeHeight);
	void setNumberOfEdges(int*noOfEdges);
	void setEdges(std::vector<int>&binFileVector);
	void addEdge(double xOne, yOne, xTwo, yTwo, boardWidth, boardHeight);
};