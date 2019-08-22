#include "arm.h"

int main(int argc, char *argv[]){
	std::cout << argv[1] << std::endl;
	Arm emulator = Arm(argv[1]);
	return 0;
}