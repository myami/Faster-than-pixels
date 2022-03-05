#pragma once
#include"SFML/Graphics.hpp"
class Button {
public:
	sf::Sprite ButtonSprite;
	bool IsSpriteClicked(sf::RenderWindow* render);
	Button();
};