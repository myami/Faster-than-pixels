#include "S_MouvementActif.h"
#include "../Components/C_Transform.h"
#include "../Components/C_Static_Render.h"


S_Mouvement_Actif::S_Mouvement_Actif()
{
}

void S_Mouvement_Actif::RunSystem(Engine::Entity* Entity, float dt)
{
	C_Transform* PlayerTransform = (C_Transform *) Entity->GetComponent("Transform");
	if (Entity->E_IsAnimated) {

	}
	else {
		if (PlayerTransform->Direction.x != 0 || PlayerTransform->Direction.y != 0 || PlayerTransform->RotationDirection != 0) {
			C_Static_Render* Static = (C_Static_Render*)Entity->GetComponent("Render");
			Static->Sprite.move(sf::Vector2f(PlayerTransform->Direction * dt));
			std::cout << "Position : X : " << Static->Sprite.getPosition().x << " Y : " << Static->Sprite.getPosition().y << " DT : " << dt << std::endl;
			Static->Sprite.setOrigin(Static->Sprite.getLocalBounds().width / 2.f, Static->Sprite.getLocalBounds().height / 2.f);
			Static->Sprite.setRotation(Static->Sprite.getRotation() + PlayerTransform->RotationDirection);
		}


	}


}
