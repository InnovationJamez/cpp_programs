#include "Chess.h"

int main(){

	int width = 8;
	int height = 8;
	std::vector<Chess_Piece*> board;

	fillBoard(&board, width, height);
	drawBoard(&board, width, height);
	selectPiece(&board, width, height);
	return 0;
}