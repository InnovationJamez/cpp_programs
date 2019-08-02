
#include <iostream>
#include <thread>

void doWork(){
	for(int i = 0; i < 10; i++){
		std::cout << "Working" << std::endl;		
	}
}


int main(){

	std::thread worker(doWork);
	worker.join(); 
	std::cout << "Work Done" << std::endl;
	std::cin.get();

	return 0;
}