#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Employees.h"

using namespace std;

int Employees::numOfEmployees =0;

Employees::setAll(string firstName,string lastName, int sallary)
{
	this -> firstName = firstName;
	this -> lastName = lastName;
	this -> sallary = sallary;
	Employee::numOfEmployees++;
}

Employeees::Employeees(string firstName,string lastName, int sallary)
{
	 this -> firstName = firstName;
	 this -> lastName = lastName;
	 this -> sallary = sallary;
}

