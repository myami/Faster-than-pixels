#include "Level0.h"
#include <iostream>
Level0::Level0():Scene("Level0")
{
}

void Level0::Begin_Play()
{
	std::cout << "Creation de la scene" << std::endl;
}

void Level0::Tick()
{
	std::cout << "Tick scene" << std::endl;

}

void Level0::End_Play()
{
	std::cout << "Destruction de la scene" << std::endl;

}
