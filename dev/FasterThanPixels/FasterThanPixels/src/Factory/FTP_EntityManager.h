#pragma once
#include "Engine.h"

/*! \class FTP_EntityManager
* \brief classe enfant de EntityManager
*
*/
class Player;
class FTP_EntityManager : public Engine::EntityManager {
	void EntityEndWaiting(Engine::Entity* entity, Engine::EntityState entitystate) override;

public:
	FTP_EntityManager();
	void GenerateEntity(Engine::Scene* sc) override;
	Player* GetPlayer();
};