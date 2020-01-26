#include "mazeBuilder.h"

// populate the maze
void populateMaze(std::vector<char>* maze, int width, int height){
	maze = new std::vector<char>;
	int len = width * height;
	for(int i = 0; i < len; i++){
		maze->push_back(0);
	}
}

// check directions chose one and return the value
int checkBorder(std::vector<char>* maze, int width, pos player){
	std::vector<int> movList;
	int choice;

	// UP
	if((*maze)[(player.y + 1) * width + player.x] & VISITED == 0){
		movList.push_back(UP);
	}
	// DOWN
	if((*maze)[(player.y - 1) * width + player.x] & VISITED == 0){
		movList.push_back(DOWN);
	}
	// LEFT
	if((*maze)[player.y * width + player.x - 1] & VISITED == 0){
		movList.push_back(LEFT);
	}
	// RIGHT
	if((*maze)[player.y * width + player.x + 1] & VISITED == 0){
		movList.push_back(RIGHT);
	}

	// select one of the choices

	return choice;
}

// once a direction is chose move that way
// set the new position as visited
// create a connection in the maze 
void walk(std::vector<char>* maze, pos* player, int choice, int width){
	switch(choice){
		case UP:
			(*maze)[player->y * width + player->x] |= UP;
			(*player).y++;
			(*maze)[player->y * width + player->x] |= DOWN;
			break;
		case DOWN:
			(*maze)[player->y * width + player->x] |= DOWN;
			(*player).y--;
			(*maze)[player->y * width + player->x] |= UP;
			break;
		case RIGHT:
			(*maze)[player->y * width + player->x] |= RIGHT;
			(*player).x++;
			(*maze)[player->y * width + player->x] |= LEFT;
			break;
		case LEFT:
			(*maze)[player->y * width + player->x] |= LEFT;
			(*player).x--;
			(*maze)[player->y * width + player->x] |= RIGHT;
			break;
		default:
			break;
	}
}

// // start ramom location, wlk, go back, walk more
void growingTree(std::vector<char>* maze, int width, int height){
	std::vector<pos> posList;
	pos player(0,0);

	srand (time(NULL));

	player.x = rand() % width;
	player.y = rand() % height;

	std::cout << player.x << std::endl;
	std::cout << player.y << std::endl;



}

// prim algorythm
void primAlgorythm(){
	std::vector<pos> posList;
	pos player(0,0);
}