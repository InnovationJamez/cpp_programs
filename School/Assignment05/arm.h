#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

// opens file and puts contents into a vector of strings
void openFile(std::string* s, std::vector<std::string>* v);

// iterates through the instruction list and calls other functions
void mainLoop(std::vector<std::string>* v, int* reg, int* mem);

// reades a line and reads the instruction
// retures a value for PC to move to 
int reader(std::string str, int* reg, int* mem);

//read value from register
int regRead(int ind, int* reg);

// write value into register
void regWrite(int val, int ind, int* reg);

//read a value from mempory
int memRead(int ind, int* mem);

// write a value into memory
void memWrite(int val, int ind, int* mem);

//print off the instructions that were loader
void instPrint(std::vector<std::string>* v);

bool wordFinder(std::string str, std::string word);


