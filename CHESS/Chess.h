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
private:
	int width = 8;
	int height = 8;
	std::vector<Chess_Piece*> board;
protected:
	point location;
	char pChar;
	std::vector<point> locations;
	bool side; //true : player 1  false : computer/player 2
public:
	// find valid move locations pure virtual 
	void virtual findLoc(std::vector<Chess_Piece*>* board, int w) = 0;
	// if the user inputs a valid location move to that location
	void move();
	// return the char that represents piece
	char returnChar();
};

class Pawn: public Chess_Piece{
public:
	// constructor
	Pawn(int x, int y);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

class Rook: public Chess_Piece{
public:
	// constructor
	Rook(int x, int y);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

class Bishop: public Chess_Piece{
public:
	// constructor
	Bishop(int x, int y);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

class Knight: public Chess_Piece{
public:
	// constructor
	Knight(int x, int y);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

class Queen: public Chess_Piece{
public:
	// constructor
	Queen(int x, int y);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

class King: public Chess_Piece{
public:
	// constructor
	King(int x, int y);
	// find valid move locations
	void findLoc(std::vector<Chess_Piece*>* board, int w) override;
};

class Empty: public Chess_Piece{
public:
	// constructor
	Empty(int x, int y);
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



