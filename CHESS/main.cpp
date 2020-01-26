#include "Chess.h"

int main(){

	fillBoard(&board, width, height);
	drawBoard(&board, width, height);
	selectPiece(&board, width, height);
	return 0;
}