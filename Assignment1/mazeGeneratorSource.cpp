#include "mazeGeneratorHeader.h"

// Maze builder functions

std::vector<std::vector<Cell>> 
boardBuilder(std::vector<std::vector<Cell>> maze,
int mazeWidth, int mazeHeight)
{    
	for(int i = 0;i < mazeWidth; ++i)
	{
		std::vector<Cell>temp;
		for(int j = 0; j < mazeHeight; ++j)
		{
			Cell condition;
			temp.push_back(condition);
		}
		maze.push_back(temp);
	}
	return maze;
}

// decide which way to walk to or go into hunting mode

int decideDirection(std::vector<std::vector<Cell>> maze, 
Coordinate position,,int mazeWidth, int mazeHeight)
{
	std::vector<directions>availableMoves[] = {'n','s','w','e'}
	
	// check north
	
	if(position.yPos == 0) // At the top of the screen
	{availableMoves.earase(0)} // remove the north option
	
	else if(maze[position.xPos][position.yPos + 1].discovered == true)
	{availableMoves.earase(0)} // remove the north option

	// check south	
	
	if(position.yPos == mazeHeight) // at the bottom of the board
	{availableMoves.earase(1)} // remove the south option	
	
	else if(maze[position.xPos][position.yPos - 1].discovered == true)
	{availableMoves.earase(1)} // remove the south option

	// check west
	
	if(position.xPos == 0) // At the left side of the screen
	{availableMoves.earase(2)} // remove the west option
	
	else if(maze[position.xPos-1][position.yPos].discovered == true)	
	{availableMoves.earase(2)} // remove the west option

	// check east

	if(position.xPos == mazeWidth) // at the far right of the board
	{availableMoves.earase(3)} // remove the east option
	
	else if(maze[position.xPos + 1][position.yPos].discovered == true)	
	{availableMoves.earase(3)} // remove the east option

	// check if the vector is empty
	
	// if not empty select a direction from the remainders on the list
	
}

// move the location and mark the connecting locations

std::vector<std::vector<Cell>>
moveNorth(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	
}
	
std::vector<std::vector<Cell>>
moveSouth(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	
}
	
std::vector<std::vector<Cell>>
moveWest(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	
}
	
std::vector<std::vector<Cell>>
moveEast(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	
}

std::vector<std::vector<Cell>> 
mazeBuilder(std::vector<std::vector<Cell>>maze,
int mazeWidth, int mazeHeight, Coordinate position)
{
	position.xPos = rand() % mazeWidth + 0;
	position.yPos = rand() % mazeHeight + 0;
	return maze;
	
}
