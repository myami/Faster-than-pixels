#pragma once
#include"SFML/Graphics.hpp"
class Button {
public:
	sf::Sprite ButtonSprite; /*!< Sprite du bouton */
	sf::Text ButtonText;/*!< Texte du bouton */
	/**
	 * @def IsSpriteClicked
	 * @brief Si la souris a cliquer sur le sprite
	 * 	\param render : la fenetre
	*/
	bool IsSpriteClicked(sf::RenderWindow* render);
	bool IsText;
	Button();
	/**
	* @def InitButton
	* @brief Initialise le bouton comme image.
	* \param Texture : l'image
	* \param pos : position du bouton
	*/
	void InitButton(sf::Texture& Texture, sf::Vector2f pos);
	/**
	* @def InitButton
	* @brief Initialise le bouton comme texte.
	* \param Text : contenu du texte.
	* \param pos : position du texte.
	* \param font : font du texte.
	* \param CharacterSize : taille de police du texte.
	*/
	void InitButton(std::string Texte, sf::Vector2f pos, sf::Font& font, int CharacterSize);
};