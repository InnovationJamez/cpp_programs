#include "DatabaseSlicer.h"

int main(){

	// time at beginging of program
	auto start = std::chrono::high_resolution_clock::now();

	// for stroing the file name given from the user
	std::string inputFileName;
	std::string outFileName;
	// get input from the user
	std::cout << "Enter the name of the input file and extension: ";
	std::cin >> inputFileName;
	std::cout << "\nEnter the name of the output file and extension: ";
	std::cin >> outFileName;
	std::cout << "\n";
	// file paths
	std::string inputFilePath = "Input/" + inputFileName;
	std::string outputFilePath = "Output/" + outFileName;
	std::string sugarDatabasePath = "SugarDatabase/Sugar_List.txt";
	// vectors
	list* foodDatabase = new list;
	list* sugarDatabase = new list;
	// load in sugar rep 
	if(!loadFile(sugarDatabasePath, sugarDatabase)){
		return 0;
	}
	// load in food rep
	if(!loadDatabase(inputFilePath, foodDatabase)){
		return 0;
	}
	// loop through database
	loopThroughDatabase(foodDatabase, sugarDatabase);

	// put in file
	storeFile(outputFilePath, foodDatabase);
	// clear up memory
	delete foodDatabase;
	delete sugarDatabase;

	// time at end of program
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end-start;

	std::cout << "Execution time " << diff.count() << " s" << std::endl; 

	return 0;
}