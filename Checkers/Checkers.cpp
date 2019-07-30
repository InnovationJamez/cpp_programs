#include "Checkers.h"

// fill board
void fillBoard(std::vector<char>* board, int width, int height){
	for(int i = 0; i < width * height){
		(*board)
	}
}

// draw the board
void drawBoard(std::vector<char>* board, int w, int h){
	for(int j = 0; j < h; j++){
		std::cout << "---------------------------------\n| ";
		for(int i = 0; i < w; i++){
			std::cout << (*board)[j * w + i] << " | ";
		}
		std::cout << "\n";		
	}
	std::cout << "---------------------------------\n";
}