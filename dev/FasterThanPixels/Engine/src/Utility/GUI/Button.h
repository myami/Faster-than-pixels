#pragma once
#include"SFML/Graphics.hpp"
class Button {
	sf::Sprite* ButtonSprite;
	bool IsSpriteClicked(sf::RenderWindow* render);
};