#include <iostream>

class pizza{
	Class(){
		std::cout << "Hello World!";
	}
};


int main(){
	pizza* p = new pizza();

	delete p;

	return 0;
}