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
		if (!Entity->E_IsAnimated) {
			C_Transform* PlayerTransform = static_cast<C_Transform*>(Entity->GetComponent("Transform"));
			if (PlayerTransform->Direction.x != 0 || PlayerTransform->Direction.y != 0 || PlayerTransform->RotationDirection != 0)
			{
				C_Static_Render* Static = static_cast<C_Static_Render*>(Entity->GetComponent("Render"));
				sf::Vector2f direction = PlayerTransform->Direction * dt;
				Static->Sprite.move(direction);
				Static->Sprite.setOrigin(Static->Sprite.getLocalBounds().width / 2.f, Static->Sprite.getLocalBounds().height / 2.f);
				Static->Sprite.setRotation(Static->Sprite.getRotation() + PlayerTransform->RotationDirection);
			}
		}
	}
}