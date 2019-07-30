#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class person{
public:
	void talk(){
		std::cout << "Hello World!" << std::endl;
	}
};

void editString(std::string* sPtr){

	*sPtr = "new string";
	std::cout << *sPtr << std::endl;
}

int main(){

	std::string s = "hello world";
	std::string* sPtr = &s;

	std::vector <person> vec;
	std::vector <person*> vecPtr;


	for(int i = 0; i < 5; i++){
		vec.push_back(person());
		vecPtr.push_back(&vec[i]);
	}

	for(person* p: vecPtr){
		p->talk();
	}

	return 0;

}