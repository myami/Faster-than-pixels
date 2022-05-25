#include "AssetManager.h"

void Engine::AssetManager::AddTexture(std::string name, std::string path)
{
	sf::Texture texture;

	texture.setSmooth(true);

	std::string origin = "./Assets";
	if (!texture.loadFromFile(origin + path))
	{
		std::cout << "Error when loadind url of the texture : " << name << std::endl;
	}
	else {
		std::cout << "Texture : " << name << "as been loaded as a texture" << texture.getSize().x << texture.getSize().y << std::endl;
		M_Textures.insert({ name,texture });
	}
}

void Engine::AssetManager::AddSound(std::string name, std::string path)
{
}

void Engine::AssetManager::AddFont(std::string name, std::string path)
{
	std::string origin = "./Assets";
	sf::Font font;
	if (!font.loadFromFile(origin + path))
	{
		std::cout << "Error when loadind url of the font : " << name << std::endl;
	}
	else {
		std::cout << "Font : " << name << "as been loaded as a font" << std::endl;
		M_Fonts.insert({ name,font });
	}
}

sf::Texture& Engine::AssetManager::GetTexture(std::string name)
{
	return  M_Textures.find(name)->second;
}

sf::Sound& Engine::AssetManager::GetSound(std::string name)
{
	return M_Sounds.find(name)->second;
}

sf::Font& Engine::AssetManager::GetFont(std::string name)
{
	return M_Fonts.find(name)->second;
}