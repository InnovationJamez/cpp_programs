#include"Character.h"
#include<iostream>
#include<string>
using namespace std;

int Character::numOfChar = 0;

Character::Character(string name, int level){
	
	this -> name = name;
	this -> level = level;
	Character::numOfChar++;
	
} 
Character::~Character(){
	cout << "Character " this -> name << 
	" has fallen in battle" << endl;
}

void Character::toString(){
	cout << this -> name << "Health: " << this -> health
	<< "\nLevel: " << this -> level << endl;
}
Character::Character(){
	numOfAnimals++;
}

int main() {
	Character bob;
	bob.setLevel(5);
	bob.setName("Bob");
}
