#include "AssetManager.h"

void Engine::AssetManager::AddTexture(std::string name, std::string path)
{
}

void Engine::AssetManager::AddSound(std::string name, std::string path)
{
}

void Engine::AssetManager::AddFont(std::string name, std::string path)
{
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
