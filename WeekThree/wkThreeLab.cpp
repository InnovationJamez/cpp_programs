#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>

using namespace std;
 
int main(){
	istringstream myFile("fruit.txt");
    for (string line; getline(myFile, line);) {
        cout << stoi(line) << endl;
    }
}