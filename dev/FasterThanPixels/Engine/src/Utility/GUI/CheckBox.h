#pragma once
#include"SFML/Graphics.hpp"

class CheckBox {
public:
	sf::Sprite CheckBoxSprite; /*!< Le background */
	sf::Sprite CheckSprite;/*!< le petit V */
	/**
	 * @def IsSpriteClicked
	 * @brief Si la souris a cliquer sur le sprite
	 * 	\param render : la fenetre
	*/
	bool IsSpriteClicked(sf::RenderWindow* render);
	bool State;
	CheckBox();

	void InitCheckBox(sf::Texture& CheckBoxTexture, sf::Texture& CheckTexture, sf::Vector2f pos, double scale, bool isActive);

};