#pragma once
#include "../Utility/Scene.h"
namespace Engine {
	class SceneManager {
		std::vector <Scene> M_Scene; // liste de toutes les scenes
		Scene& GetScene(std::string);
		void AddScene(Scene);


	};
}