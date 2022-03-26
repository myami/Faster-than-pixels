#pragma once
#include "SFML/Graphics/Texture.hpp"

class Slider {
	float CurrentPosition;
public:
	sf::Texture Background;
	sf::Texture SliderBar;
	Slider();

	void SetSlider(float position);
	float GetSliderPosition();
};