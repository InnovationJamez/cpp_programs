#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

typedef struct{
	int day;
	int month;
	int year;
	
}Date;

class Employees {
private:
	string firstName;
	string lastName;
	int sallary;
	Date birthDay;
public:
	static int numOfEmployees;
	
	string getFirstName(){return firstName;}
	string getLastName(){return lastName;}
	int getSallary(){return sallary;}
	
	Date getBirthday(){return birthDay;}
	string setFirstName(string firstNamae)
	{firstName = firstNamae;}
	string setLastName(string lastNamae)
	{lastName = lastNamae;}
	
	int setSallary(int dollar){sallary = dollar;}
	Date getBirthday(Date day){birthDay = day;}
	
	int increaseSallary(int raise);
	
	Employees();
	
	~Employees();
	
	void toString(string, string, int);
};