#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class UserData{
private:
	std::string name;
	int age;
	std::string favoriteColor;
public:
	UserData(std::string n, int a, std::string fc);
	void PrintData(int n);
	void StoreData(std::fstream* file); 
};

class GameSaveLoader{
private:
	std::vector<UserData*> UserDataList;
	std::fstream fileData;
	std::string filePath = "gameData.txt";
public:
	GameSaveLoader();
	void ClearData();
	void AddUser();
	void PrintUserData();
	void StoreUserData();
	void PrintOptions();
	void LoadUserData();
};