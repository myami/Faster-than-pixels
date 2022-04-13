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


Engine::S_Delay_Entity Engine::GenerateEntity(Engine::EntityManager* entman, std::string Tag)
{

    S_Delay_Entity entite;
    entite.E_ID = entman->RequestEntity();
    entite.E_Tag = Tag;

    return entite;
}


