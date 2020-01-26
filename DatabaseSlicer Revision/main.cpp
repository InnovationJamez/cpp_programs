#include "DatabaseSlicer.h"

int main(){

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
	if(!loadSugarData(sugarDatabasePath, sugarDatabase)){
		return 0;
	}
	// load in food rep
	if(!loadFile(inputFilePath, foodDatabase)){
		return 0;
	}

	// store the elements in four lists
	list* upcList = new list;
	list* brandList = new list;
	list* descList = new list;
	list* ingrediantList = new list;
	list* nameList = new list;

	// split data into four columns 
	splitDataCatagories(upcList, brandList, descList, ingrediantList, foodDatabase);

	// clear up memory
	delete foodDatabase;

	// make the name column by combining brand and description
	combineColumns(brandList, descList, nameList);

	// clear up brand and description as they are no longer needed
	delete brandList;
	delete descList;

	// remove the non sugars
	removeNonSugars(sugarDatabase, ingrediantList);

	// sugar list no longer needed
	delete sugarDatabase;

	// put in file
	storeFile(outputFilePath, upcList, nameList, ingrediantList);

	// clear up memory
	delete upcList;
	delete ingrediantList;
	delete nameList;

	return 0;
}