#pragma once
#include"SFML/Graphics.hpp"
class Button {
public:
	sf::Sprite ButtonSprite; /*!< Sprite du bouton */
	/**
	 * @def IsSpriteClicked
	 * @brief Si la souris a cliquer sur le sprite
	 * 	\param render : la fenetre
	*/
	bool IsSpriteClicked(sf::RenderWindow* render);
	Button();
};