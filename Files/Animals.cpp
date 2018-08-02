#include<iostream>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

class Animal
{
private:
	int height;
	int weight;
	int name;
	static int numOfAnimals;
public;
	int getHeight(){return height;}
	int getWeight(){return weight;}
	string getName(){return name;}
	void setHeight(int cm){height = cm;}
	void setWeight(int kg){weight = kg;}
	void setName(string dogName){name = dogName;}
	
	void setAll(int, int string);
	
	Animal(int, int, string);
	
	~Animal();
	
	Animal();
	
	static int getNumOfAnimals() {return numOfAnimals;}
	
	void toString();
};

int Animal::numOfAnimals =0;

void Animal::setAll(int height, int weight, string name) {
	this -> height = height;
	this -> weight = weight;
	this -> name = name;
	Animal::numOfAnimals++;
}

Animal::Animal(int height, int weight, string name){
	this -> height = height;
	this -> weight = weight;
	this -> name = name;
}

Animal::~Animal(){
	cout << "Animal " << this -> name << " destroyed" << endl;
}

Animal::Animal(){
	numOfAnimals++;
}

void Animal::toString(){
	cout << this -> name << " is " << this -> height << " cms tall and "
	<< this -> weight << " kgs in weight" << endl;
}

class Dog : public Animal {
private:
	string sound = "Woof"
public:
	void getSound() {cout << sound << endl;
	Dog(int, int, string, string);
	Dog():Animal(){};
	void toString();	
};

Dog::Dog(int height, int weight, int weight, string name, string bark):
Animal(height, weight, name){
	this -> sound = bark;
}

void Dog::toString(){
	cout << this -> getName() << " is "
}

// Declare a Animal type object
	Animal fred;
 
	// Set the values for the Animal
	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");
 
	// Get the values for the Animal
	cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
		<< fred.getWeight() << " kgs in weight" << endl;
 
	fred.setAll(34, 12, "Fred");
 
	cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
		<< fred.getWeight() << " kgs in weight" << endl;
 
	// Creating an object using the constructor
	Animal tom(36, 15, "Tom");
 
	cout << tom.getName() << " is " << tom.getHeight() << " cms tall and "
		<< tom.getWeight() << " kgs in weight" << endl;
 
	// Demonstrate the inheriting class Dog
	Dog spot(38, 16, "Spot", "Woof");
 
	// static methods are called by using the class name and the scope operator
	cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;
 
	spot.getSound();
 
	// Test the toString method that will be overwritten
	tom.toString();
	spot.toString();
 
	// We can call the superclass version of a method with the class name 
	// and the scope operator
	spot.Animal::toString();
 
	// When a function finishes it must return an integer value
	// Zero means that the function ended with success
	return 0;
}