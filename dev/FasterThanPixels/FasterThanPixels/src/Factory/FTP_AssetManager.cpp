#include "FTP_AssetManager.h"
#include "Engine.h"
#include <json.hpp>




void FTP_AssetManager::InitAsset()
{
	std::vector<nlohmann::json> tmpassetfile = Engine::LoadAssetFromFile();
	for (size_t i = 0; i < tmpassetfile.size(); i++)
	{
		std::string type = tmpassetfile[i]["type"].get<std::string>();
		if (type._Equal("Texture")) {
			std::cout << "Textures : " << tmpassetfile[i]["name"].get<std::string>() << std::endl;
			AddTexture(tmpassetfile[i]["name"].get<std::string>(), tmpassetfile[i]["url"].get<std::string>());
		}
		else if (type._Equal("Font")) {
			std::cout << "Font : " << tmpassetfile[i]["name"].get<std::string>() << std::endl;
			AddFont(tmpassetfile[i]["name"].get<std::string>(), tmpassetfile[i]["url"].get<std::string>());
		}
	}
}
