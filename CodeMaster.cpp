#include <iostream>
#include <time.h>
#include <string>

int main(){
	char colors[6] = {'r', 'g', 'b', 'y', 'o', 'p'};
	char code[6];
	char guess[6];
	bool correct = false;
	int guessCount = 0;

	srand(time(NULL));

	for(int i = 0; i < 6; i++){
		code[i] = colors[rand() % 6];
	}


	std::cout << "Colors\nRed: 'r'\nGreen: 'g'\nBlue: 'b'\n" 
		"Yellow: 'y'\nOrange: 'o'\nPurple: 'p'\n" << std::endl;
	std::cout << "guess the colors\nc1 c2 c3 c4 c5 c6" << std::endl;

	while(!correct){
		std::cin >> guess[0] >> guess[1] >> guess[2] >> 
			guess[3] >> guess[4] >> guess[5];

		for(int i = 0; i < 6; i++){
			if(guess[i] != code[i]){
				correct = false;
				break;
			}
			else{
				correct = true;
			}
		}

		for(int i = 0; i < 6; i++){
			std::cout << (guess[i] == code[i] ? "O" : "X") << " ";
		}
		guessCount++;
		std::cout << " Guess Number: " << guessCount << std::endl;
	}

	std::cout << "You Win!" << std::endl;

}