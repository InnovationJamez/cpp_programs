#include<fstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Header.h
class Character{
private:
	int xPos, yPos;
	string name;
	int level;
	int health;
	int dexterity;
	int defence;
	int charisma;
	int intellagence;
	static int numOfChar;
public:
	string getName(){return name;}
	int getHealth(){return health;}
	int getdefence(){return defence;}
	int getCharisma(){return charisma;}
	int getIntellagence(){return intellagence;}
	
	void setName(string charName){name = charName;}
	void setLevel(int charLevel){level = charLevel;}
	
	Charactrer(string,int);
	~Character();
	Character();
	static int getNumOfChar(){return numOfChar;}
	void toString();
} ;

	
	
	
	
	