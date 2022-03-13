#include "Utility.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <vector>
#include "../ECS/Entity.h"


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

void Engine::InitEnvironnement(int seed, Engine::EntityManager* entman)
{
    srand(seed / 2);
    int Amount_Planet = rand();
    srand(seed / 5);
    int Amount_Asteroid = rand();

    for (size_t i = 0; i < Amount_Planet; i++)
    {
       Entity* newplanet =  entman->RequestEntity();
       newplanet->E_CanBeUsed = false;
       newplanet->E_Tag = "Planet";
       entman->EntityChangeMap(newplanet, "Default", "Planet");

    }

    for (size_t i = 0; i < Amount_Asteroid; i++)
    {
        Entity* newasteroid = entman->RequestEntity();
        newasteroid->E_CanBeUsed = false;
        newasteroid->E_Tag = "Asteroid";
        entman->EntityChangeMap(newasteroid, "Default", "Asteroid");
    }



}
