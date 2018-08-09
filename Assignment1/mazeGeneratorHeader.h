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
	const int mazeWidth = 4;
	const int mazeHeight = 4;
	std::vector<std::vector<Cell>>maze;

public:

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
	
};