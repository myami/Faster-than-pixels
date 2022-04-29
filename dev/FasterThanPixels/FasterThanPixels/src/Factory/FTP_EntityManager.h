#pragma once
#include "Engine.h"
/*! \class FTP_EntityManager
* \brief classe enfant de EntityManager
*
*/
class FTP_EntityManager : public Engine::EntityManager {
	void EntityEndWaiting(Engine::Entity* entity, Engine::EntityState entitystate) override;
};