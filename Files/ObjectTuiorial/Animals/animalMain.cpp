int Animal::numOfAnimals = 0;
 
// Define the protoype method setAll
void Animal::setAll(int height, int weight, string name){
 
	// This is used to refer to an object created of this class type
	this -> height = height;
	this -> weight = weight;
	this -> name = name;
	Animal::numOfAnimals++;
 
}
 
// A constructor is called when an object is created
Animal::Animal(int height, int weight, string name) {
 
	this -> height = height;
	this -> weight = weight;
	this -> name = name;
 
}
 
// The destructor is called when an object is destroyed
Animal::~Animal() {
 
	cout << "Animal " << this -> name << " destroyed" << endl;
 
}
 
// A constructor called when no attributes are passed
Animal::Animal() {
	numOfAnimals++;
}
 
// This method prints object info to screen and will be overwritten
void Animal::toString(){
 
	cout << this -> name << " is " << this -> height << " cms tall and "
		<< this -> weight << " kgs in weight" << endl;
 
}
int main() {
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