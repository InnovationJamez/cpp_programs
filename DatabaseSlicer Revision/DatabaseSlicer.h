#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<chrono>

#define list std::vector<std::string>

// fload file into vector of strings
bool loadFile(std::string filePath, list* fileVector);

// fload in the sugar database while setting all characters to uppercase
bool loadSugarData(std::string filePath, list* fileVector);

// load database
bool loadDatabase(std::string filePath, list* fileVector);

// split the data into its catagories
void splitDataCatagories(list* upc, list* brand, list* desc, list* ingred, list* data);

// stor a vector of strings into a file
void storeFile(std::string filePath, list* upc, list* name, list* ingred);

// remove all the non sugars from the ingrediants
void removeNonSugars(list* sugarList, list* ingredList);

// take the ingrediant string and return a list of ingrediants
list stringToList(std::string s);

// take the list and return a string
std::string listToString(list l);

// check if it is a added sugar
bool checkIngredient(std::string item, list* sugarList);

// combine two columns
void combineColumns(list* brand, list* desc, list* name);

// print the contents of a vector
void printVector(list* vec);
