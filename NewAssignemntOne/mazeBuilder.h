// MazeBuilder header file

#include<iostream>
#include<vector>
#include<random>
#include<fstream>

struct Cell
{
	bool northConnection = false;
	bool southConnection = false;
	bool eastConnection = false;
	bool westConnection = false;
	bool discovered = false;
};

struct coords
{
	int xPos, yPos;
};

enum DIRECTION {
	NORTH = 1,
	SOUTH = 2,
	WEST = 3,
	EAST = 4,
	NONE = 5
};

class MazeGenerator
{
private:
	std::fstream binFile;
	coords position;
	int mazeWidth;
	int mazeHeight;
	std::vector<std::vector<Cell>>maze;
public:


	// set position
	void setPosition(int i, int j);

	// get input for dimensions of maze
	void takeVallues(int mazeWidth, int mazeHeight);

	// fill in the maze

	void boardBuilder();

	// checkBoundries

	bool checkNorthBound();

	bool checkSouthBound();

	bool checkWestBound();

	bool checkEastBound();

	// check surounding spaces
	bool checkNorth();

	bool checkSouth();

	bool checkWest();

	bool checkEast();

	// check canMove

	bool canMoveNorth();

	bool canMoveSouth();

	bool canMoveWest();

	bool canMoveEast();

	// hunt check

	void huntChecker(int i, int j);

	/*
	This part of the program will be filling the
	maze. It will start at a random location.
	Then it will start the walk. Then go into
	hunt mode
	*/

	// Generates a random number

	double randomNumber(double upperbound);

	// placeStart

	void placeStart();

	// decine direction

	DIRECTION decideDirection();

	// walk in direction

	void walkNorth();

	void walkSouth();

	void walkWest();

	void walkEast();

	void setDiscovered();

	// connect prieces

	void connectNorth();

	void connectSouth();

	void connectWest();

	void connectEast();

	// walk mode

	void walkMode();

	// hunt mode

	void huntMode();

	/*
	Binary Files creation
	*/

	// open binary file

	void openBinFile(std::string binFileName);

	// count the number of enges

	double countEdges();

	// set first three numbers

	void setFirstThreeNumbers();

	// connection checker

	void mazeConnectionChecker();

	// connection checker

	void setEdge(coords a, coords b);

	// set coords

	coords setSouthWallA(int i, int j);
	coords setSouthWallB(int i, int j);

	coords setEastWallA(int i, int j);
	coords setEastWallB(int i, int j);

	// convert int to bin

	std::string intToBin(int num);

	// store the edges into the bin file

	void binFileEditor(std::string input);

	// close the binary file

	void closeBinFile();
};
