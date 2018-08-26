// mazeBuilder source file

#include "MazeBuilder.h"

// set Position

void MazeGenerator::setPosition(int i, int j)
{
	this->position.xPos = i;
	this->position.yPos = j;
}

// get input for dimensions of maze

void MazeGenerator::takeVallues(int mazeWidth, int mazeHeight)
{
	this->mazeWidth = mazeWidth;
	this->mazeHeight = mazeHeight;
}

// fill in the maze

void MazeGenerator::boardBuilder()
{
	for (int i = 0; i < (this->mazeWidth); i++)
	{
		std::vector<Cell>temp;
		for (int j = 0; j < (this->mazeHeight); j++)
		{
			Cell condition;
			temp.push_back(condition);
		}
		this->maze.push_back(temp);
	}
}

// checkBoundries 

bool MazeGenerator::checkNorthBound() {
	if (this->position.yPos == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkSouthBound() {
	if (this->position.yPos == (this->mazeHeight - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkWestBound() {
	if (this->position.xPos < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkEastBound()
{
	if (this->position.xPos == (this->mazeWidth - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// check position

bool MazeGenerator::checkNorth()
{
	if (this->maze[this->position.xPos]
		[this->position.yPos - 1].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkSouth()
{
	if (this->maze[this->position.xPos]
		[this->position.yPos + 1].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkWest()
{
	if (this->maze[this->position.xPos - 1]
		[this->position.yPos].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkEast()
{
	if (this->maze[this->position.xPos + 1]
		[this->position.yPos].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// check canMove

bool MazeGenerator::canMoveNorth() {
	if (!checkNorthBound())
	{
		if (!checkNorth())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::canMoveSouth() {
	if (!checkSouthBound())
	{
		if (!checkSouth())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::canMoveWest() {
	if (!checkWestBound())
	{
		if (!checkWest())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::canMoveEast() {
	if (!checkEastBound())
	{
		if (!checkEast())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

// Generates a random number

double MazeGenerator::randomNumber(double upperBound)
{
	double randomNumber;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, (upperBound - 1));
	randomNumber = dis(gen);
	return randomNumber;
}

// place start

void MazeGenerator::placeStart()
{
	// find a random spot on the maze and set
	// the coordinates to that point
	setPosition(MazeGenerator::randomNumber(this->mazeWidth),
		randomNumber(this->mazeHeight));
	setDiscovered();
}


// during walk decine direction

DIRECTION MazeGenerator::decideDirection()
{
	std::vector<DIRECTION>tempVector;
	if (canMoveNorth()) {
		tempVector.push_back(NORTH);
	}
	if (canMoveSouth()) {
		tempVector.push_back(SOUTH);
	}
	if (canMoveWest()) {
		tempVector.push_back(WEST);
	}
	if (canMoveEast()) {
		tempVector.push_back(EAST);
	}
	if (tempVector.size() == 0) {
		return NONE;
	}
	else
	{
		return tempVector[randomNumber(tempVector.size())];
	}
}

// Connect the pieces as it moves

void MazeGenerator::connectNorth()
{
	this->maze[this->position.xPos]
		[this->position.yPos].northConnection = true;
	this->maze[this->position.xPos]
		[this->position.yPos - 1].southConnection = true;
}

void MazeGenerator::connectSouth()
{
	this->maze[this->position.xPos]
		[this->position.yPos].southConnection = true;
	this->maze[this->position.xPos]
		[this->position.yPos + 1].northConnection = true;
}

void MazeGenerator::connectWest()
{
	this->maze[this->position.xPos]
		[this->position.yPos].westConnection = true;
	this->maze[this->position.xPos - 1]
		[this->position.yPos].eastConnection = true;
}

void MazeGenerator::connectEast()
{
	this->maze[this->position.xPos]
		[this->position.yPos].eastConnection = true;
	this->maze[this->position.xPos + 1]
		[this->position.yPos].westConnection = true;
}

///////////          walk in direction             //////////////

void MazeGenerator::walkNorth()
{
	this->position.yPos -= 1;
}

void MazeGenerator::walkSouth()
{
	this->position.yPos += 1;
}

void MazeGenerator::walkWest()
{
	this->position.xPos -= 1;
}

void MazeGenerator::walkEast()
{
	this->position.xPos += 1;
}

void MazeGenerator::setDiscovered()
{
	this->maze[this->position.xPos]
		[this->position.yPos].discovered = true;
}

// walk mode

void MazeGenerator::walkMode()
{
	DIRECTION direction = MazeGenerator::decideDirection();
	switch (direction)
	{
	case NORTH:
		connectNorth();
		walkNorth();
		setDiscovered();
		walkMode();
		break;
	case SOUTH:
		connectSouth();
		walkSouth();
		setDiscovered();
		walkMode();
		break;
	case WEST:
		connectWest();
		walkWest();
		setDiscovered();
		walkMode();
		break;
	case EAST:
		connectEast();
		walkEast();
		setDiscovered();
		walkMode();
		break;
	case NONE:
		huntMode();
		break;
	default:
		std::cout << "error in the decide direction function" << std::endl;
	}
}

// hunt check

void MazeGenerator::huntChecker(int i, int j)
{
	setPosition(i, j);
	if (!checkNorthBound())
	{

		if (checkNorth())
		{
			connectNorth();
			setDiscovered();
			walkMode();
		}
	}
	if (!checkSouthBound())
	{
		if (checkSouth())
		{
			connectSouth();
			setDiscovered();
			walkMode();
		}
	}
	if (!checkWestBound())
	{
		if (checkWest())
		{
			connectWest();
			setDiscovered();
			walkMode();
		}
	}
	if (!checkEastBound())
	{
		if (checkEast())
		{
			connectEast();
			setDiscovered();
			walkMode();
		}
	}
}

// hunt Mode

void MazeGenerator::huntMode()
{
	for (int j = 0; j < this->mazeHeight; ++j)
	{
		for (int i = 0; i < this->mazeWidth; ++i)
		{
			if (maze[i][j].discovered == false)
			{
				huntChecker(i, j);
			}
		}
	}
}

/*
		Binary Files creation
*/

void MazeGenerator::openBinFile(std::string binFileName)
{
	this->binFile.open(binFileName.c_str(),
		std::ios::in | std::ios::out | std::ios::trunc);
}

double MazeGenerator::countEdges()
{
	double count = 0;
	for (int j = 0; j < (this->mazeHeight); j++)
	{
		for (int i = 0; i < (this->mazeWidth); i++)
		{
			if (this->maze[i][j].eastConnection == false)
			{
				count++;
			}
		}
	}
	for (int i = 0; i < (this->mazeWidth); i++)
	{
		for (int j = 0; j < (this->mazeWidth); j++)
		{
			if (this->maze[i][j].southConnection == false)
			{
				count++;
			}
		}
	}
	return count;
}

void MazeGenerator::setFirstThreeNumbers()
{
	binFileEditor(intToBin(this->mazeWidth));
	binFileEditor(intToBin(this->mazeWidth));
	binFileEditor(intToBin(countEdges()));
}

coords MazeGenerator::setSouthWallA(int i, int j)
{
	coords a;
	a.xPos = i;
	a.yPos = j;
	return a;
}

coords MazeGenerator::setSouthWallB(int i, int j)
{
	coords b;
	b.xPos = i;
	b.yPos = j + 1;
	return b;
}

coords MazeGenerator::setEastWallA(int i, int j)
{
	coords a;
	a.xPos = i;
	a.yPos = j;
	return a;
}

coords MazeGenerator::setEastWallB(int i, int j)
{
	coords b;
	b.xPos = i + 1;
	b.yPos = j;
	return b;
}

void MazeGenerator::mazeConnectionChecker()
{
	for (int j = 0; j < (this->mazeHeight); j++)
	{
		for (int i = 0; i < (this->mazeWidth); i++)
		{
			if (this->maze[i][j].eastConnection == false)
			{
				coords a = setEastWallA(i, j);
				coords b = setEastWallB(i, j);
				setEdge(a, b);
			}
		}
	}
	for (int i = 0; i < (this->mazeWidth); i++)
	{
		for (int j = 0; j < (this->mazeWidth); j++)
		{
			if (this->maze[i][j].southConnection == false)
			{
				coords a = setSouthWallA(i, j);
				coords b = setSouthWallB(i, j);
				setEdge(a, b);
			}
		}
	}
}

void MazeGenerator::setEdge(coords a, coords b)
{
	binFileEditor(intToBin(a.xPos));
	binFileEditor(intToBin(a.yPos));
	binFileEditor(intToBin(b.xPos));
	binFileEditor(intToBin(b.yPos));
}

std::string MazeGenerator::intToBin(int num)
{
	std::string binNum;
	while (num > 0)
	{
		if (num % 2 == 1)
		{
			binNum = '1' + binNum;
		}
		else
		{
			binNum = '0' + binNum;
		}
		num = num / 2;
	}
	while (binNum.size() < 32)
	{
		binNum = '0' + binNum;
	}
	return binNum;
}

void MazeGenerator::binFileEditor(std::string input)
{
	for (int counter = 0; counter <= (int)input.size(); counter++) {
		this->binFile.put(input[counter]);
	}
}

void MazeGenerator::closeBinFile()
{
	this->binFile.close();
}

int stringToInt(std::string numberString) 
{
	int numberInt = std::stoi(numberString);
	return numberInt;
}

int main(int argc, char*argv[])
{
	if(argc == 4)
	{
		std::string binFileName = argv[1];
		int width = stringToInt(argv[2]);
		int height = stringToInt(argv[3]);
		MazeGenerator mazeOne;
		mazeOne.takeVallues(width, height);
		mazeOne.boardBuilder();
		mazeOne.placeStart();
		mazeOne.walkMode();
		mazeOne.openBinFile(binFileName);
		mazeOne.setFirstThreeNumbers();
		mazeOne.mazeConnectionChecker();
		mazeOne.closeBinFile();
	}
	else
	{
		std::cout << "incorrect number of argc" << std::endl;
	}
	return 0;	
}
