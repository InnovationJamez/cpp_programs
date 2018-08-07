#include<iostream>
#include<vector>

enum directions {North = 'n', South = 's', East = 'e', West = 'w'};


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
	Coordinate position;
	int mazeWidth = 4;
	int mazeHeight = 4;
		
	std::vector<std::vector<Cell>>maze;
	
public:

	// Return functions

	std::vector<std::vector<Cell>> getMaze(){return maze;}
	Coordinate getPosition(){return position;}
	int getHeight(){return mazeHeight;}
	int getWidth(){return mazeWidth;}

	// Maze builder functions

	std::vector<std::vector<Cell>> 
	boardBuilder(std::vector<std::vector<Cell>> 
	maze, int mazeWidth, int mazeHeight);
	
	std::vector<std::vector<Cell>> 
	mazeBuilder(std::vector<std::vector<Cell>> maze,
	int mazeWidth, int mazeHeight, Coordinate position);
	
	// decide which way to walk to or go into hunting mode
	
	int decideDirection(std::vector<std::vector<Cell>> maze, 
	Coordinate position,int mazeWidth, int mazeHeight);
	
	
	// move the location and mark the connecting locations
	
	std::vector<std::vector<Cell>>
	moveNorth(std::vector<std::vector<Cell>> maze, Coordinate position);
	
	std::vector<std::vector<Cell>>
	moveSouth(std::vector<std::vector<Cell>> maze, Coordinate position);
	
	std::vector<std::vector<Cell>>
	moveWest(std::vector<std::vector<Cell>> maze, Coordinate position);
	
	std::vector<std::vector<Cell>>
	moveEast(std::vector<std::vector<Cell>> maze, Coordinate position);
	
	
	// conversion to binary file
	
	void createBinaryFile();
	
	
	
};