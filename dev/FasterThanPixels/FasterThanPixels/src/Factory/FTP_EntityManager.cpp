#include "FTP_EntityManager.h"
#include "../ECS/Components/C_Static_Render.h"
#include "../ECS/Components/C_Animated_Render.h"

void FTP_EntityManager::EntityEndWaiting(Engine::Entity* entity, Engine::EntityState entitystate)
{
	switch (entitystate)
	{
	case Engine::EntityState::None:
		break;
	case Engine::EntityState::Add:
		if (entity->E_Tag.compare("Asteroid"))
		{
			C_Static_Render* AsteroidRender = dynamic_cast<C_Static_Render*>(entity->GetComponent("Render"));
			if (AsteroidRender)
				Engine::GeneratePhysicBody(this, entity->E_Id, AsteroidRender->Sprite.getPosition(), sf::Vector2f(0, 0), sf::Vector2f(AsteroidRender->Sprite.getGlobalBounds().width / 2, AsteroidRender->Sprite.getGlobalBounds().height / 2), b2_staticBody, GameManager->G_SceneManager->GetCurrentScene()->SCALE, GameManager->G_SceneManager->GetCurrentScene()->World);
		}
		else if (entity->E_Tag.compare("Planet"))
		{
			C_Animated_Render* CheckAnimatation = dynamic_cast<C_Animated_Render*>(entity->GetComponent("Render"));
			if (CheckAnimatation)
				Engine::GeneratePhysicBody(this, entity->E_Id, CheckAnimatation->AnimatedSprite.FrameToDraw().getPosition(), sf::Vector2f(0, 0), sf::Vector2f(CheckAnimatation->AnimatedSprite.FrameToDraw().getGlobalBounds().width / 2, CheckAnimatation->AnimatedSprite.FrameToDraw().getGlobalBounds().height / 2), b2_staticBody, GameManager->G_SceneManager->GetCurrentScene()->SCALE, GameManager->G_SceneManager->GetCurrentScene()->World);
		}
		else if (entity->E_Tag.compare("Player"))
		{
			C_Static_Render* AsteroidRender = dynamic_cast<C_Static_Render*>(entity->GetComponent("Render"));
			if (AsteroidRender)
				Engine::GeneratePhysicBody(this, entity->E_Id, AsteroidRender->Sprite.getPosition(), sf::Vector2f(0, 0), sf::Vector2f(AsteroidRender->Sprite.getGlobalBounds().width / 2, AsteroidRender->Sprite.getGlobalBounds().height / 2), b2_staticBody, GameManager->G_SceneManager->GetCurrentScene()->SCALE, GameManager->G_SceneManager->GetCurrentScene()->World);
		}
		break;
	case Engine::EntityState::Delete:
		break;
	case Engine::EntityState::AddComponent:
		break;
	case Engine::EntityState::DeleteComponent:
		break;
	default:
		break;
	}
}