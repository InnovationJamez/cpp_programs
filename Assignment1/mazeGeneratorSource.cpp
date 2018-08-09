#include "mazeGeneratorHeader.h"

// Maze builder functions

void MazeGenerator::boardBuilder(std::vector<std::vector<Cell>> &maze,
int* mazeWidth, int* mazeHeight)
{    
	for(int i = 0;i < *mazeWidth; ++i)
	{
		std::vector<Cell>temp;
		for(int j = 0; j < *mazeHeight; ++j)
		{
			Cell condition;
			temp.push_back(condition);
		}
		maze.push_back(temp);
	}
}

void MazeGenerator::mazeBuilder(std::vector<std::vector<Cell>> &maze,
int* mazeWidth, int* mazeHeight,Coordinate* position)
{
	position->xPos = rand() % (*mazeWidth-1) + 0;
	position->yPos = rand() % (*mazeHeight-1) + 0;	
	
	int answer = MazeGenerator::decideDirection(maze, &mazeWidth, &mazeHeight, position);
}

// decide which way to walk to or go into hunting mode

int MazeGenerator::decideDirection(std::vector<std::vector<Cell>> &maze, 
int* mazeWidth, int* mazeHeight,Coordinate* position)
{
	std::vector<int>availableMoves;
	
	// check north
	if(!((position->yPos == 0)||(maze[position->xPos][position->yPos + 1].discovered == true)))
	{availableMoves.push_back(1);}

	// check south	
	if(!((position->yPos == *mazeHeight)||(maze[position->xPos][position->yPos - 1].discovered == true)))
	{availableMoves.push_back(2);}

	// check west
	if(!((position->xPos == 0)||(maze[position->xPos-1][position->yPos].discovered == true)))	
	{availableMoves.push_back(3);}

	// check east
	if(!((position->xPos == *mazeWidth)||(maze[position->xPos + 1][position->yPos].discovered == true)))	
	{availableMoves.push_back(4);}

	// check if the vector is empty
	
	if(availableMoves.size() == 0)
	{
		return 5;
	}
	// if not empty select a direction from the remainders on the list
	else
	{
		return availableMoves[rand() % (availableMoves.size()-1) + 0];
	}
}

// Hunt Mode
void MazeGenerator::huntMode(std::vector<std::vector<Cell>> &maze,
int* mazeWidth, int* mazeHeight, Coordinate* position)
{
	
	for(int j = 0; j < *mazeHeight; ++j)
	{
		for(int i = 0;i < *mazeWidth; ++i)
			{
				if(maze[i][j].discovered == true)
				position->xPos = i;
				position->yPos = j;
				{break;}
			}
	}
}

/*	
// move the location and mark the connecting locations

// Move north
void MazeGenerator::moveNorth(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	// move one space north
	position.xPos
	position.yPos
	
	// birdge the top of the current piece with the bottom of the new position
	maze[position.xPos][position.yPos].northConnection = true;
	maze[position.xPos][position.yPos + 1].southConnection = true;
}


void MazeGenerator::moveSouth(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	position.xPos
	position.yPos	
}
	
void MazeGenerator::moveWest(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	position.xPos
	position.yPos
}
	
void MazeGenerator::moveEast(std::vector<std::vector<Cell>> maze, Coordinate position)
{
	position.xPos
	position.yPos	
}

void MazeGenerator::mazeBuilder(std::vector<std::vector<Cell>>maze,
int mazeWidth, int mazeHeight, Coordinate position)
{
	position.xPos = rand() % mazeWidth + 0;
	position.yPos = rand() % mazeHeight + 0;
	return maze;
	
}
*/