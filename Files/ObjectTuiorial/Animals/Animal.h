#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Animal
{
 
// private variables are only available to methods in the class
private:
	int height;
	int weight;
	string name;
 
	// A static variable shares the same value with every object in the class
	static int numOfAnimals;
 
// Public variables can be accessed by anything with access to the object
public:
	int getHeight(){return height;}
	int getWeight(){return weight;}
	string getName(){return name;}
	void setHeight(int cm){ height = cm; }
	void setWeight(int kg){ weight = kg; }
	void setName(string dogName){ name = dogName; }
 
	// Declared as a prototype
	void setAll(int, int, string);
 
	// Declare the constructor
	Animal(int, int, string);
 
	// Declare the deconstructor
	~Animal();
 
	// An overloaded constructor called when no data is passed
	Animal();
 
	// protected members are available to members of the same class and 
	// sub classes
 
	// Static methods aren't attached to an object and can only access
	// static member variables
	static int getNumOfAnimals() { return numOfAnimals; }
 
	// This method will be overwritten in Dog
	void toString();
 
};