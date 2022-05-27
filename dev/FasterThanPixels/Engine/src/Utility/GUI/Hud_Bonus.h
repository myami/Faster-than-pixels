#pragma once
#include"SFML/Graphics.hpp"

namespace Engine {
	class Hud_Bonus {
		sf::Font Font; /*!< Police d'�criture */
		sf::Vector2f PositionOrigin; /*!< Position */
		sf::Sprite Icon; /*!< Icone */
		sf::Text CurrentValue; /*!< Valeur actuelle */
		sf::Text MaxValue; /*!< Valeur maximale */
	public:

		Hud_Bonus();
		/**
		* @def InitHudBonus
		* @brief Initialise le bonus dans le Head Up Display.
		* \param IconTexture : le sprite de l'ic�ne.
		* \param BonusMaxValue : quantit� maximum du bonus. 
		* \param BonusCurrentValue : quantit� actuelle du bonus. 
		* \param FontAddress : r�f�rence � la police de charact�re dans le G_AssetManager.
		* \param CharacterSize : taille de la police de charact�re.
		* \param PositionOrigin : Position de l'affichage du Bonus.
		*/
		void InitHudBonus(sf::Texture& IconTexture, std::string BonusMaxValue, std::string BonusCurrentValue, sf::Font& FontAddress, int CharacterSize, sf::Vector2f PositionOrigin);
		/**
		* @def GetIcon
		* @brief Retourne le sprite de l'ic�ne.
		* \return le sprite de l'ic�ne
		*/
		sf::Sprite GetIcon();
		/**
		* @def GetMaxValue
		* @brief Retourne la valeur max du bonus.
		* \return la valeur max
		*/
		sf::Text GetMaxValue();

		/**
		* @def SetCurrentValue
		* @brief �tablie la valeur courante du bonus.
		* \param CurrentValue : valeur � set.
		*/
		void SetCurrentValue(std::string CurrentValue);
		/**
		* @def GetCurrentValue
		* @brief Retourne la valeur courante du bonus.
		* \return  un sf::Text de la valeur courante 
		*/
		sf::Text GetCurrentValue();
	};
}