#pragma once
#include <map>
#include <string>
#include "../Utility/Utility.h"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Engine {
	class AssetManager {
		std::map<std::string, sf::Texture> M_Textures;
		std::map<std::string, sf::Sound> M_Sounds;
		std::map<std::string, sf::Font> M_Fonts;
	public:
		void AddTexture(std::string name, std::string path);
		void AddSound(std::string name, std::string path);
		void AddFont(std::string name, std::string path);
		sf::Texture& GetTexture(std::string name);
		sf::Sound& GetSound(std::string name);
		sf::Font& GetFont(std::string name);
		virtual void InitAsset() = 0;

	};
}