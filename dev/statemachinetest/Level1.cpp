#include "Level1.h"
#include <iostream>

Level1::Level1() :Scene("Level1")
{
}

void Level1::Begin_Play()
{
	std::cout << "Creation de la scene 1 " << std::endl;
}

void Level1::Tick()
{
	std::cout << "\r" << " Tick scene 0";
	std::cin >> input;
	if (input == 'p') {
		param.isterminal = true;
		param.StopState = true;
		std::cout << "changement scene";
	}
}

void Level1::End_Play()
{
	std::cout << "Destruction de la scene 1 " << std::endl;

}
