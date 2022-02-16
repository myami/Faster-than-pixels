#pragma once
#include "../Utility/Scene.h"
#include <vector>

namespace Engine {
	class SceneManager {
	public:
		std::vector <Scene*> M_Scene; // liste de toutes les scenes
		Scene& GetScene(std::string);
		Scene& GetCurrentScene(std::string scene);

		void AddScene(Scene* scene);
		virtual void Init() =0;


	};
}