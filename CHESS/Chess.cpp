#include "Chess.h"

/*
	Chess_Piece
*/

// if the user inputs a valid location move to that location
void Chess_Piece::move(){
	
}

// return the char that represents piece
char Chess_Piece::returnChar(){
	return pChar;
}

/*
	Pawn Derived Class
*/

// constructor
Pawn::Pawn(int x, int y){
	location.xPos = x;
	location.yPos = y;
	pChar = 'p';
}

// find valid move locations
void Pawn::findLoc(std::vector<Chess_Piece*>* board, int w){
	
}

/*
	Rook Derived Class
*/

// constructor
Rook::Rook(int x, int y){
	location.xPos = x;
	location.yPos = y;	
	pChar = 'r';
}

// find valid move locations
void Rook::findLoc(std::vector<Chess_Piece*>* board, int w){

}

/*
	Bishop Derived Class
*/

// constructor
Bishop::Bishop(int x, int y){
	location.xPos = x;
	location.yPos = y;
	pChar = 'b';
}

// find valid move locations
void Bishop::findLoc(std::vector<Chess_Piece*>* board, int w){

}

/*
	Knight Derived Class
*/

// constructor
Knight::Knight(int x, int y){
	location.xPos = x;
	location.yPos = y;
	pChar = 'k';
}

// find valid move locations
void Knight::findLoc(std::vector<Chess_Piece*>* board, int w){

}

/*
	Queen Derived Class
*/

// constructor
Queen::Queen(int x, int y){
	location.xPos = x;
	location.yPos = y;
	pChar = 'q';
}

// find valid move locations
void Queen::findLoc(std::vector<Chess_Piece*>* board, int w){

}

/*
	King Derived Class
*/

// constructor
King::King(int x, int y){
	location.xPos = x;
	location.yPos = y;
	pChar = 'k';
}

// find valid move locations
void King::findLoc(std::vector<Chess_Piece*>* board, int w){
	std::vector<point> temp;
	temp.push_back({location.xPos + 1, location.yPos});
	temp.push_back({location.xPos - 1, location.yPos});
	temp.push_back({location.xPos, location.yPos + 1});
	temp.push_back({location.xPos, location.yPos - 1});

	for(int i = 0; i < temp.size(); i++){
		if((*board)[temp[i].yPos * w + temp[i].xPos]->returnChar() == ' '){
			locations.push_back(temp[i]);
		}
	}


	for(int i = 0; i < locations.size(); i++){
		std::cout << locations[i].xPos << " " << locations[i].yPos << std::endl;
	}
}

/*
	Empty Derived Class
*/

// constructor
Empty::Empty(int x, int y){
	location.xPos = x;
	location.yPos = y;
	pChar = ' ';
}

// find valid move locations
void Empty::findLoc(std::vector<Chess_Piece*>* board, int w){

}

/*

	Non Methonds

*/

// populate the board 
void fillBoard(std::vector<Chess_Piece*>* board, int w, int h){
	for(int i = 0; i < w * h; i++){
		for(int j = 0; j < h; j++){
			if(i == 5 && j == 5){
				(*board).push_back(new King(i, j));
			}
			else{
				(*board).push_back(new Empty(i, j));				
			}

		}
	}
}

// draw the board
void drawBoard(std::vector<Chess_Piece*>* board, int w, int h){
	for(int j = 0; j < h; j++){
		std::cout << "---------------------------------\n| ";
		for(int i = 0; i < w; i++){
			std::cout << (*board)[j * w + i]->returnChar() << " | ";
		}
		std::cout << "\n";		
	}
	std::cout << "---------------------------------\n";
}

// select piece
void selectPiece(std::vector<Chess_Piece*>* board, int w, int h){
	int x, y;
	std::cout << "Enter x and y range(1 - 8) of the piece you want seportated by a space\nEnter here: ";
	std::cin >> x >> y;

	if(x > 0 && x <= w && y > 0 && y <= h){
		std::cout << "You selected: "<< (*board)[(y - 1) * w + (x - 1)]->returnChar() << std::endl;
		(*board)[(y - 1) * w + (x - 1)]->findLoc(board, w);
	}
}


