#include "Utility.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <vector>
#include "../ECS/Entity.h"
#include "../ECS/Component.h"
#include "../Factory/EntityManager.h"

std::vector<nlohmann::json> Engine::LoadAssetFromFile(std::string path)
{
	nlohmann::json j;

	std::vector<std::filesystem::path> fileasset;
	std::vector<nlohmann::json> assets;
	for (const auto& file : std::filesystem::directory_iterator(path)) { // prend tout les chemins de fichier json dans un vector
		if (!file.is_directory()) {
			fileasset.push_back(file.path());
			std::cout << " Json for asset available :" << file.path() << std::endl;
		}
	}
	for (size_t i = 0; i < fileasset.size(); i++) // lie les fichier json et enregistre leur contenu dans la memoire
	{
		std::cout << "Loading json assets : " << fileasset[i] << std::endl;
		std::ifstream file(fileasset[i]);
		nlohmann::json j;
		file >> j;
		assets.push_back(j);
	}

	return assets;
}

void Engine::SerializeData(std::map<std::string, int>& params) {

	nlohmann::json settings(params);
	std::string filename = "./settings.json";
	std::ofstream file(filename);
	file << settings;

}

std::map<std::string, int> Engine::GetInfoFromJSON(std::string path) {
	nlohmann::json j;
	std::map < std::string, int> SettingsParam;
	std::ifstream settings_file(path);
	settings_file >> j;
	SettingsParam = j;

	return SettingsParam;
}

bool Engine::FileExists(std::string path)
{
	return std::filesystem::exists(path);
}



Engine::S_Delay_Entity Engine::GenerateEntity(Engine::EntityManager* entman, std::string Tag)
{
	S_Delay_Entity entite;
	entite.E_ID = entman->RequestEntity(Tag);
	return entite;
}

void Engine::GeneratePhysicBody(Engine::EntityManager* entman, int identity, sf::Vector2f position, sf::Vector2f direction, sf::Vector2f bound, b2BodyType type, int scale, b2World* World)
{
	b2BodyDef BodyDef = b2BodyDef();
	BodyDef.position = b2Vec2(position.x / scale, position.y / scale);
	BodyDef.type = type;
	b2Body* Body = World->CreateBody(&BodyDef);
	b2CircleShape circle;
	circle.m_p.Set(bound.x, bound.y);
	circle.m_radius = bound.x;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 100.f;
	FixtureDef.friction = 0.f;
	FixtureDef.shape = &circle;
	Body->CreateFixture(&FixtureDef);
	entman->M_PhysicMap.insert({ Body,identity });
}