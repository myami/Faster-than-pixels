#pragma once
#include "Engine.h"
#include "..\Scene\Starting.h"
/*! \class FTP_SceneManager
* \brief classe enfant de SceneManager
*
*/
class FTP_SceneManager : public Engine::SceneManager {
public:
	void Init(std::string FirstScene);
	FTP_SceneManager(Engine::GameManager* gm);
};