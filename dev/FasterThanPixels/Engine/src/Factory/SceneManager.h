#pragma once
#include "../Utility/Scene.h"
#include "GameManager.h"
#include <vector>

namespace Engine {
	class SceneManager {
	public:
		SceneManager();
		SceneManager(Engine::GameManager* gm);
		std::vector <Scene*> M_Scene; // liste de toutes les scenes
		Scene& GetScene(std::string);
		Scene& GetCurrentScene();
		Engine::GameManager* _GameManager;
		void AddScene(Scene* scene);
		virtual void Init() =0;



	};
}