#include<iostream>
#include<vector>
#include<string>
#include <time.h>

#define VISITED 1
#define UP 2
#define DOWN 4
#define LEFT 8
#define RIGHT 16

struct pos{
	int x;
	int y;

	pos(int xPos, int yPos){
		x = xPos;
		y = yPos;
	}
};

// populate the maze
void populateMaze(std::vector<char>* maze, int width, int height);

// check directions chose one and return the value
int checkBorder(std::vector<char>* maze, int width, pos player);

// once a direction is chose move that way
// set the new position as visited
// create a connection in the maze 
void walk(std::vector<char>* maze, pos* player, int choice);

// start ramom location, wlk, go back, walk more
void growingTree(std::vector<char>* maze, int width, int height);

// prim algorythm
void primAlgorythm();
