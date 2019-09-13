#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<chrono>

#define list std::vector<std::string>

// fload file into vector of strings
bool loadFile(std::string filePath, list* fileVector);

// load database
bool loadDatabase(std::string filePath, list* fileVector);

// loop through the food database, find key words, remove non important ingreediants
void loopThroughDatabase(list* fdv, list* sList);

// take a string and remove a array without the spaces
list sliceString(std::string s);

// take an array and remove the none important parts
void cutArray();

// take the cut array and return a string that wil be a line of the database
void makeDataLine();

// stor a vector of strings into a file
void storeFile(std::string filePath, list* fileVector);

// check if it is a added sugar
bool checkIngredient(std::string item, list* sugarList);

// correct errors by removing bad new line characters
void fixErrors(list* database);

// print the contents of a vector
void printVector(list* vec);
