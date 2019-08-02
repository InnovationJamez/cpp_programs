#include "mazeBuilder.h"


int main(){

	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> runTime;

	start = std::chrono_system_time.now();

	const int width = 30;
	const int height = 30;

	std::vector<int> maze;

	end = std::chrono_system_time.now();
	runTime = end - start;

	std::cout << "Elapsed time" << runTime.count() << std::endl;

	return 0;
}