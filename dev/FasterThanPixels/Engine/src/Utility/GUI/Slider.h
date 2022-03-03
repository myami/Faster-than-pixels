#pragma once
#include "SFML/Graphics/Texture.hpp"

class Slider {
public:
	sf::Texture Background;
	sf::Texture Slider;
	float CurrentPosition;

	void SetSlider(float position);
	float GetSliderPosition();
};