#pragma once
#include <map>
#include <string>
#include "../Utility/Utility.h"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Engine {
	/*! \class AssetManager
	* \brief classe representant tout les assets disponible dans le jeux
	*
	*/
	class AssetManager {
		std::map<std::string, sf::Texture> M_Textures; /*!< Liste des textures */
		std::map<std::string, sf::Sound> M_Sounds; /*!< Liste des sons */
		std::map<std::string, sf::Font> M_Fonts; /*!< Liste des fonts */
	public:
		/*!
		*  \brief Ajoute une texture dans la liste.
		*
		*
		* \param name : Nom de la texture
		* \param path : Chemin de la texture
		*/
		void AddTexture(std::string name, std::string path);
		/*!
		* \brief Ajoute un son dans la liste.
		*
		* \param name : Nom du son
		* \param path : Chemin du son
		*/
		void AddSound(std::string name, std::string path);
		/*!
		* \brief Ajoute une font dans la liste.
		*
		* \param name : Nom de la font
		* \param path : Chemin de la font
		*/
		void AddFont(std::string name, std::string path);
		/*!
		* \brief Returne une texture?
		*
		* Retourne une texture par rapport a son nom.
		*
		* \param name : Nom de la texture
		* \return la texture selectionner
		*/
		sf::Texture& GetTexture(std::string name);
		/*!
		* \brief Retourne un son.
		*
		* Retourne un son par rapport a sont nom.
		*
		* \param name : Nom du son.
		* \return le son selectionné.
		*/
		sf::Sound& GetSound(std::string name);
		/*!
		* \brief Retourne une font.
		*
		* Retourne une font par rapport a sont nom.
		*
		* \param name : Nom de la font.
		*
		* \return la font selectionner
		*/
		sf::Font& GetFont(std::string name);
		/*!
		*  \brief Charge les assets dans les listes.
		*/
		virtual void InitAsset() = 0;
	};
}