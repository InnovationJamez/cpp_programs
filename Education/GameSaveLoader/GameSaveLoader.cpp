#include "GameSaveLoader.h"

int main(){

	GameSaveLoader loader;

	return 0;
}

/* 

	user data class

*/

UserData::UserData(std::string n, int a, std::string fc)
	:name(n), age(a), favoriteColor(fc)
{
	// stuff will go here
}

void UserData::PrintData(int n){
	std::cout << "Index Number: " << n << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Favorite Color: " << favoriteColor << std::endl;
}

void UserData::StoreData(std::fstream* file){
	(*file) << name << "\n";
	(*file) << age << "\n";
	(*file) << favoriteColor << "\n";
}

/* 

	game save loader class 

*/

GameSaveLoader::GameSaveLoader(){
	char input;
	while(input != '5'){
		PrintOptions();
		
		std::cin >> input;

		switch(input){
			case '1':
				AddUser();
				break;
			case '2':
				PrintUserData();
				break;
			case '3':
				StoreUserData();
				break;
			case '4':
				LoadUserData();
				break;
			case '5':
				break;
			default:
				std::cout << "Invalid Input" << std::endl;
				break;
		}
	}

	ClearData();
}

void GameSaveLoader::ClearData(){
	int len = UserDataList.size();

	for(int i = 0; i < len; i++){
		delete UserDataList[i];
	}

	UserDataList.clear();
}

void GameSaveLoader::AddUser(){

	std::string name, favoriteColor;
	int age;

	std::cout << "Enter a name: ";
	std::cin >> name;
	std::cout << "Enter an age: ";
	std::cin >> age;
	std::cout << "Enter Favorite Color: ";
	std::cin >> favoriteColor;
	std::cout << "\n"; 

	UserDataList.push_back(new UserData(name, age, favoriteColor));

}

void GameSaveLoader::PrintUserData(){
	int len = UserDataList.size();

	std::cout << "\nUSERS START\n" << std::endl;

	for(int i = 0; i < len; i++){
		UserDataList[i]->PrintData(i);
	}

	std::cout << "\nUSERS END\n" << std::endl;
}

void GameSaveLoader::StoreUserData(){
	int len = UserDataList.size();

	fileData.open(filePath, std::fstream::out);

	if(fileData.is_open()){
		std::cout << "\nFILE OPENED SUCCSESSFULLY!" << std::endl;
		for(int i = 0; i < len; i++){
		UserDataList[i]->StoreData(&fileData);
		}
		std::cout << "\nUSER SAVE COMPLETE\n" << std::endl;
	}
	else{
		std::cout << "Failed to open the file" << std::endl;
	}
	fileData.close();
}

void GameSaveLoader::PrintOptions(){
	std::cout << "OPTIONS" << std::endl;
	std::cout << "1: Add User" << std::endl;
	std::cout << "2: Print Users" << std::endl;
	std::cout << "3: Save Users" << std::endl;
	std::cout << "4: Load User Data" << std::endl;
	std::cout << "5: Close Program" << std::endl;
	std::cout << "Enter Here: ";
}

void GameSaveLoader::LoadUserData(){
	fileData.open(filePath, std::fstream::in);

	if(fileData.is_open()){
		std::cout << "\nFILE OPENED SUCCSESSFULLY!" << std::endl;
		// empty user data vector
		ClearData();

		std::string line;
		int cnt = 0;

		std::string name, favoriteColor;
		int age;

		// read lines into vector
		while(std::getline(fileData, line)){
			switch(cnt){
				case 0:
					name = line;
					cnt++;
					break;
				case 1:
					age = std::stoi(line);
					cnt++;
					break;
				case 2:
					favoriteColor = line;
					UserDataList.push_back(new UserData(name, age, favoriteColor));
					cnt = 0;
					break;
				default:
					std::cout << "Error" << std::endl;
					break;
			}
		}

		std::cout << "\nUSER DATA LOAD COMPLETE\n" << std::endl;
	}
	else{
		std::cout << "Failed to open the file" << std::endl;
	}

	fileData.close();
}