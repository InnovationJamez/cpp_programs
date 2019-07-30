
#include <iostream>
#include <thread>

void doWork(){
	std::cout << "Working" << std::endl;
}


int main(){

	std::thread worker(doWork);
	//worker.join();

	return 0;
}