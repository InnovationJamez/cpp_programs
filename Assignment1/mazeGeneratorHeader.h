#include<iostream>
#include<vector>

struct Cell
{
	bool northConnection = false;
	bool southConnection = false;
	bool eastConnection = false;
	bool westConnection = false;
	bool discovered = false;
};

struct Coordinate
{
	int xPos;
	int yPos;
};

class MazeGenerator{

private:

	// Variables

	Coordinate position;
	
	int mazeWidth;
	int mazeHeight;
	std::vector<std::vector<Cell>>maze;

	
public:

/*
	these functions check to see if the current 
	spot is on one of the boundaries 
*/

	void takeVallues(int* mazeWidth,int* mazeHeight);

	bool checkNorthBound(Coordinate* position,int* 
	mazeWidth,int* mazeHeight);

	bool checkSouthBound(Coordinate* position,int* 
	mazeWidth,int* mazeHeight);
	
	bool checkEastBound(Coordinate* position,int* 
	mazeWidth,int* mazeHeight);
	
	bool checkWestBound(Coordinate* position,int* 
	mazeWidth,int* mazeHeight);

/*
	These functions check the surounding spaces 
	to see is they are taken
*/

	bool checkNorth(std::vector<std::vector<Cell>> &maze,
	Coordinate* position);
	
	bool checkSouth(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);
	
	bool checkEast(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);
	
	bool checkWest(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);

	// Maze builder functions

	void boardBuilder(std::vector<std::vector<Cell>> &maze,
	int* mazeWidth, int* mazeHeight);
		
	void mazeBuilder(std::vector<std::vector<Cell>> &maze,
	int* mazeWidth, int* mazeHeight,Coordinate* position);
	
	// decide which way to walk to or go into hunting mode
	
	int decideDirection(std::vector<std::vector<Cell>> &maze, 
	int* mazeWidth, int* mazeHeight,Coordinate* position);
	
	// Hunt Mode
	
	void huntMode(std::vector<std::vector<Cell>> &maze,
	int* mazeWidth, int* mazeHeight, Coordinate* position);

	// move the location and mark the connecting locations
	
	void moveNorth(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);
	
	void moveSouth(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);
	
	void moveWest(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);
	
	void moveEast(std::vector<std::vector<Cell>> &maze, 
	Coordinate* position);
	
	// conversion to binary file
	
	void createBinaryFile();
	
	// Constructor
};