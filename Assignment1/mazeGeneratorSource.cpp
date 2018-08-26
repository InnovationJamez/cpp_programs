#include "mazeGeneratorHeader.h"

// Maze builder functions

void MazeGenerator::takeVallues(int* mazeWidth,int* mazeHeight)
{
	int width, height;
	std::cout << "Enter Maze width then height and hit enter" << std::endl;
	std::cin >> width >>height;
	std::cout << "\nYou entered a height: "<<height<<" and width: "<<width<<std::endl;
	
}

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

// check if spot is on a boundrie

bool MazeGenerator::checkNorthBound(Coordinate* position,int* mazeWidth,int* mazeHeight)
{
	bool answer;
	if(position->yPos == 0)
	{
		answer = true;		
	}
	else
	{
		answer = false;
	}
	return answer;
}
	
bool MazeGenerator::checkSouthBound(Coordinate* position,int* mazeWidth,int* mazeHeight)
{
	bool answer;
	if(position->yPos == *mazeHeight)
	{
		answer = true;	
	}
	else
	{
		answer = false;
	}
	return answer;
}

bool MazeGenerator::checkEastBound(Coordinate* position,int* mazeWidth,int* mazeHeight)
{
	bool answer;
	if(position->xPos == *mazeWidth)
	{
		answer = true;	
	}
	else
	{
		answer = false;
	}
	return answer;
}
	
bool MazeGenerator::checkWestBound(Coordinate* position,int* mazeWidth,int* mazeHeight)
{
	bool answer;
	if(position->xPos == 0)
	{
		answer = true;		
	}
	else
	{
		answer = false;
	}
	return answer;
}	

// chack if surounding spots are taken
	
bool MazeGenerator::checkNorth(std::vector<std::vector<Cell>> &maze,
Coordinate* position)
{
	bool answer;
	if(maze[position->xPos][position->yPos + 1].discovered == true)
	{
		
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

bool MazeGenerator::checkSouth(std::vector<std::vector<Cell>> &maze, 
Coordinate* position)
{
	bool answer;
	if(maze[position->xPos][position->yPos - 1].discovered == true)	
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}
	
bool MazeGenerator::checkEast(std::vector<std::vector<Cell>> &maze, 
Coordinate* position)
{
	bool answer;
	if(maze[position->xPos+1][position->yPos].discovered == true)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;	
}
	
bool MazeGenerator::checkWest(std::vector<std::vector<Cell>> &maze, 
Coordinate* position)
{
	bool answer;
	if(maze[position->xPos-1][position->yPos].discovered == true)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

// decide which way to walk to or go into hunting mode

int MazeGenerator::decideDirection(std::vector<std::vector<Cell>> &maze, 
int* mazeWidth, int* mazeHeight,Coordinate* position)
{
	/* 
	Check to see if the position is on one of of the boundires 
	then check to see if the next spot in that direction is empty
	if it is empty then that direction is added to the list of 
	available moves that will be selected from by the randomizer 
	*/
/*
	std::vector<int>availableMoves;

	if(!(MazeGenerator::checkNorthBound(position, mazeWidth, mazeHeight)))
	{
		if(!(MazeGenerator::checkNorth(maze, position)))
		{availableMoves.push_back(1);}
	}
	if(!(MazeGenerator::checkSouthBound(position, mazeWidth, mazeHeight)))
	{
		if(!(MazeGenerator::checkSouth(maze, position)))
		{availableMoves.push_back(2);}
	}
	if(!(MazeGenerator::checkEastBound(position, mazeWidth, mazeHeight)))
	{
		if(!(MazeGenerator::checkEast(maze, position)))
		{availableMoves.push_back(3);}
	}
	if(!(MazeGenerator::checkWestBound(position, mazeWidth, mazeHeight)))
	{
		if(!(MazeGenerator::checkWest(maze, position)))
		{availableMoves.push_back(4);}
	}
	
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
	
/* Look for undicovered space and check the surounding nieghbor cells
	if they are all undiscovered then move on to next cell until it finds an 
	undiscovered cell with a discovered nieghbor cell
*/
/*
	std::vector<int>availableMoves;
	
	for(int j = 0; j < *mazeHeight; ++j)
	{
		for(int i = 0;i < *mazeWidth; ++i)
			{
				if(maze[i][j].discovered == false)
				{
					if(!(MazeGenerator::checkNorthBound(position, mazeWidth, mazeHeight)))
					{
						if(MazeGenerator::checkNorth(maze, position))
						{	
							position->yPos = j; position->xPos = i;
							maze[position->xPos][position->yPos].northConnection = true;
							maze[position->xPos][position->yPos-1].southConnection = true;
							MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
						}
					}
			
					if(MazeGenerator::checkSouthBound(position, mazeWidth, mazeHeight))
					{
						if(MazeGenerator::checkSouth(maze, position))
						{	
							position->yPos = j; position->xPos = i;
							maze[position->xPos][position->yPos].southConnection = true;
							maze[position->xPos][position->yPos+1].northConnection = true;
							MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
						}
					}	
					
					if(MazeGenerator::checkWestBound(position, mazeWidth, mazeHeight))
					{
						if(MazeGenerator::checkWest(maze, position))
						{
							position->yPos = j; position->xPos = i;
							maze[position->xPos][position->yPos].westConnection = true;
							maze[position->xPos-1][position->yPos].eastConnection = true;
							MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
						}
					}	
					
					if(MazeGenerator::checkEastBound(position, mazeWidth, mazeHeight))
					{
						if(MazeGenerator::checkEast(maze, position))
						{
							position->yPos = j; position->xPos = i;
							maze[position->xPos][position->yPos].eastConnection = true;
							maze[position->xPos+1][position->yPos].westConnection = true;
							MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
						}
					}						
				}
			}
	}
}

/*
	As the piece moves the place it used to be will be connected to the place it is moving to
*/
/*
void MazeGenerator::moveNorth(std::vector<std::vector<Cell>> &maze, Coordinate* position)
{
	// birdge the top of the current piece with the bottom of the new position
	maze[position->xPos][position->yPos].northConnection = true;
	maze[position->xPos][position->yPos-1].southConnection = true;
	
	// move one space north
	position->yPos -= 1;
}


void MazeGenerator::moveSouth(std::vector<std::vector<Cell>> &maze,Coordinate* position)
{	
	// bridge the bottom of the current piece with the top of the new position
	maze[position->xPos][position->yPos].southConnection = true;
	maze[position->xPos][position->yPos+1].northConnection = true;	

	// move one space south
	position->yPos += 1;
}
	
void MazeGenerator::moveWest(std::vector<std::vector<Cell>> &maze,Coordinate* position)
{
	// bridge the bottom of the current piece with the top of the new position
	maze[position->xPos][position->yPos].westConnection = true;
	maze[position->xPos-1][position->yPos].eastConnection = true;	

	// move one space south
	position->xPos -= 1;
}
	
void MazeGenerator::moveEast(std::vector<std::vector<Cell>> &maze,Coordinate* position)
{
	// bridge the bottom of the current piece with the top of the new position
	maze[position->xPos][position->yPos].eastConnection = true;
	maze[position->xPos+1][position->yPos].westConnection = true;	

	// move one space south
	position->xPos += 1;
}

/* 
	this is where the maze will be built
*/
/*
void MazeGenerator::mazeBuilder(std::vector<std::vector<Cell>> &maze,
int* mazeWidth, int* mazeHeight,Coordinate* position)
{
	position->xPos = rand() % (*mazeWidth-1) + 0;
	position->yPos = rand() % (*mazeHeight-1) + 0;
	int moveNum;
	moveNum = MazeGenerator::decideDirection(maze, mazeWidth, mazeHeight,position);
	switch (moveNum) 
	{
	case 1:
		MazeGenerator::moveNorth(maze,position);
		MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
		break;
	case 2:
		MazeGenerator::moveSouth(maze,position);
		MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
		break;
	case 3:
		MazeGenerator::moveWest(maze,position);
		MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
		break;
	case 4:
		MazeGenerator::moveEast(maze,position);
		MazeGenerator::mazeBuilder(maze,mazeWidth,mazeHeight,position);
		break;
	case 5:
		MazeGenerator::huntMode(maze,mazeWidth,mazeHeight,position);
	default:
		std::cout << "there has been an error" << std::endl;
	}
}
*/