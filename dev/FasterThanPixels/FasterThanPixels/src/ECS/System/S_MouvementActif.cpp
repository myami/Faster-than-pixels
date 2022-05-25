#include "S_MouvementActif.h"
#include "../Components/C_Transform.h"
#include "../Components/C_Static_Render.h"
#include <SFML/Graphics.hpp>

S_Mouvement_Actif::S_Mouvement_Actif()
{
}

void S_Mouvement_Actif::RunSystem(float dt)
{
	for (auto const& Entity : EntityLoop) 
	{
		C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(Entity->GetComponent("Transform"));
		if (!Entity->E_IsAnimated) {
			if (PlayerTransform->Direction.x != 0 || PlayerTransform->Direction.y != 0 || PlayerTransform->RotationDirection != 0) 
			{
				C_Static_Render* Static = dynamic_cast<C_Static_Render*>(Entity->GetComponent("Render"));
				Static->Sprite.move(sf::Vector2f(200,0));
				std::cout << "Position : X : " << Static->Sprite.getPosition().x << " Y : " << Static->Sprite.getPosition().y << " DT : " << dt << std::endl;
				Static->Sprite.setOrigin(Static->Sprite.getLocalBounds().width / 2.f, Static->Sprite.getLocalBounds().height / 2.f);
				Static->Sprite.setRotation(Static->Sprite.getRotation() + PlayerTransform->RotationDirection);
			}
		}
	}



}
