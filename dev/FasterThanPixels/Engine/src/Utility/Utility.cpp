#include "Utility.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"


void Engine::LoadAssetFromFile()
{
    nlohmann::json j;

    std::vector<std::filesystem::path> fileasset;
    std::string path = "./Assets";
    std::vector<nlohmann::json> assets;
    for (const auto& file : std::filesystem::directory_iterator(path)) { // prend tout les chemins de fichier json dans un vector
        if (!file.is_directory()) {
            fileasset.push_back(file.path());
            std::cout << "Json for asset available :" << file.path() << std::endl;
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

    //std::cout << assets[0]["type"];


}
