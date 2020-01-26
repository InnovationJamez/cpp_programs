#include "Chess.h"

/*
	Chess_Piece
*/

// if the user inputs a valid location move to that location
void Chess_Piece::move(std::vector<Chess_Piece*>* board, int w){
	int choice;
	if(locList.size() > 0){
		std::cout << "Select Location: " << std::endl;
		for(int i = 0; i < locList.size(); i++){
			std::cout << i << " [" << locList[i].xPos << "," << 
				locList[i].yPos << "]" << std::endl;
		}
		std::cout << "Enter choice here: ";
		std::cin >> choice;
		std::cout << "you chose: " << locList[choice].xPos << " " << locList[choice].yPos << std::endl;

		(*board)[locList[choice].yPos * w + locList[choice].xPos] = (*board)[loc.yPos * w + loc.xPos];
		(*board)[loc.yPos * w + loc.xPos] = nullptr;
		loc = locList[choice];
	}
}

// return the char that represents piece
char Chess_Piece::returnChar(){
	return pChar;
}

/*
	Pawn Derived Class
*/

// constructor
Pawn::Pawn(int x, int y, bool playSide){
	loc.xPos = x;
	loc.yPos = y;
	side = playSide;
	pChar = 'p';
}

// find valid move locations
void Pawn::findLoc(std::vector<Chess_Piece*>* board, int w){
	int direction = (side) ? 1 : -1;
	std::vector<point> temp;

	temp.push_back({loc.xPos, loc.yPos + direction});

	if((*board)[loc.yPos * w + loc.xPos] != nullptr){
		temp.push_back({loc.xPos + 1, loc.yPos + direction});
	}
	if((*board)[loc.yPos * w + loc.xPos] != nullptr){
		temp.push_back({loc.xPos - 1, loc.yPos + direction});
	}
}

/*
	King Derived Class
*/

// constructor
King::King(int x, int y, bool playSide){
	loc.xPos = x;
	loc.yPos = y;
	side = playSide;
	pChar = 'k';
}

// find valid move locations
void King::findLoc(std::vector<Chess_Piece*>* board, int w){
	locList.clear();
	std::cout << "finding spaces" << std::endl;
	std::vector<point> temp;
	temp.push_back({loc.xPos + 1, loc.yPos});
	temp.push_back({loc.xPos - 1, loc.yPos});
	temp.push_back({loc.xPos, loc.yPos + 1});
	temp.push_back({loc.xPos, loc.yPos - 1});

	for(int i = 0; i < temp.size(); i++){
		if((*board)[temp[i].yPos * w + temp[i].xPos] == nullptr){
			locList.push_back(temp[i]);
		}
	}
}

/*

	Non Methonds

*/

// populate the board 
void fillBoard(std::vector<Chess_Piece*>* board, int w, int h){
	for(int i = 0; i < w * h; i++){
		for(int j = 0; j < h; j++){
			(*board).push_back(nullptr);
		}
	}
	(*board)[0 * w + 4] = new Pawn(4, 0, true);
	(*board)[5 * w + 5] = new Pawn(5, 5, false);
}

// draw the board
void drawBoard(std::vector<Chess_Piece*>* board, int w, int h){
	std::cout << "-------------------------------------\n";
	std::cout << "| X | ";
	for(int i = 0; i < w; i++){
		std::cout << i << " | ";
	}
	std::cout << "\n";
	for(int j = 0; j < h; j++){
		std::cout << "-------------------------------------\n| " << j << " | ";
		for(int i = 0; i < w; i++){
			if((*board)[j * w + i] != NULL){
				std::cout << (*board)[j * w + i]->returnChar() << " | ";
			}
			else{
				std::cout << "  | ";
			}
		}
		std::cout << "\n";		
	}
	std::cout << "-------------------------------------\n";
}

// select piece
void selectPiece(std::vector<Chess_Piece*>* board, int w, int h){
	int x, y;
	std::cout << "Enter x and y range(0 - 7) of the piece you want seportated by a space\nEnter here: ";
	std::cin >> x >> y;

	if(x > 0 && x <= w && y > 0 && y <= h && (*board)[y * w + x] != NULL){
		std::cout << "You selected: "<< (*board)[y * w + x]->returnChar() << std::endl;
		(*board)[y * w + x]->findLoc(board, w);
		(*board)[y * w + x]->move(board, w);
	}
	else {
		std::cout << "this space is empty" << std::endl;
	}
}