#include "mazeBuilder.h"


int main(){

	int width = 3;
	int height = 3;

	std::vector<char>* maze;

	populateMaze(maze, width, height);
	growingTree(maze, width, height);

	return 0;
}