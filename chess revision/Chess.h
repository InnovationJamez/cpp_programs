#include<vector>
#include<iostream>

/*
KEY
p:	pawn
r: 	rook
n: 	knight
b: 	bishop
k: 	king
q: 	queen
*/

struct point{
	int xPos, yPos;
};

class Chess_Piece{
protected:
	point loc;
	char pChar;
	std::vector<point> locList;
	bool side; //true : player 1  false : computer/player 2
public:
	// find valid move locations pure virtual 
	void virtual findLoc(std::vector<Chess_Piece*>* board, int w) = 0;
	// if the user inputs a valid location move to that location
	void move(std::vector<Chess_Piece*>* board, int w);
	// return the char that represents piece
	char returnChar();
};

/*
	Pawn Derived Class
*/

class Pawn: public Chess_Piece{
public:
	// constructor
	Pawn(int x, int y, bool playSide);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

/*
	King Derived Class
*/

class King: public Chess_Piece{
public:
	// constructor
	King(int x, int y, bool playSide);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

/*

	Non Methonds

*/

// populate the board 
void fillBoard(std::vector<Chess_Piece*>* board, int w, int h);

// draw the board
void drawBoard(std::vector<Chess_Piece*>* board, int w, int h);

// select piece
void selectPiece(std::vector<Chess_Piece*>* board, int w, int h);