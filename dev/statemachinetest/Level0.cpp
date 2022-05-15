#include "Level0.h"
#include <iostream>
Level0::Level0():Scene("Level0")
{
}

void Level0::Begin_Play()
{
	std::cout << "Creation de la scene 0 " << std::endl;
}

void Level0::Tick()
{
	std::cout << "\r" << " Tick scene 0";

	std::cin >> input;
	if (input == 'o') {
		param.isterminal = false;
		param.NextScene = "Level1";
		param.StopState = true;
		std::cout << "changement scene";
	}

}

void Level0::End_Play()
{
	std::cout << "Destruction de la scene 0 " << std::endl;

}
