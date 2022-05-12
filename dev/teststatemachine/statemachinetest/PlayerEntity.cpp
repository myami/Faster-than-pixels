#include "PlayerEntity.h"
#include <iostream>

PlayerEntity::PlayerEntity():Entity("Player")
{
}

void PlayerEntity::Begin_Play()
{
	std::cout << "Creation du joueur" << std::endl;
}

void PlayerEntity::Tick()
{
	std::cout << "loop joueur" << std::endl;
}

void PlayerEntity::End_Play()
{
	std::cout << "Destruction du joueur" << std::endl;
}
