#include <iostream>

void printHello(){
	std::cout << "Hello" << std::endl;
}

void printBye(){
	std::cout << "Bye" << std::endl;
}

// taks refrence to function and calls function n times
void loopFunc(void (*func)()){
	for(int i = 0; i < 5; i++){
		func();
	}
}

int main(void){

	loopFunc(printHello);
	loopFunc(printBye);

	std::cout << "Press enter to continue ";
	std::cin.get();
}