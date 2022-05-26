#pragma once
#include"SFML/Graphics.hpp"

class CheckBox {
public:
	sf::Sprite CheckBoxSprite; /*!< Le background */
	sf::Sprite CheckSprite;/*!< le petit V */
	/**
	* @def IsSpriteClicked
	* @brief Si la souris a cliquer sur le sprite
	* \param render : la fenetre
	*/
	bool IsSpriteClicked(sf::RenderWindow* render);

	bool State;
	CheckBox();

	/**
	* @def IsSpriteClicked
	* @brief Si la souris a cliquer sur le sprite
	* \param CheckBoxTexture : le sprite de la checkbox
	* \param CheckTexture : le sprite de la coche
	* \param pos : le vecteur de position
	* \param scale : l'echelle des sprites
	* \param isActive : détermine l'état de la checkbox
	*/
	void InitCheckBox(sf::Texture& CheckBoxTexture, sf::Texture& CheckTexture, sf::Vector2f pos, double scale, bool isActive);

};