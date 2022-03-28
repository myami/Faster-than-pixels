#pragma once
#include "SFML/Graphics.hpp"
namespace Engine {

class Slider {
	float CurrentPosition;
public:
	sf::Sprite Background;
	sf::Sprite SliderBar;
	Slider();
	int step;
	int min;
	int max;
	bool orientation; // true == horizontal, false = vertical

	void InitSlider(int min, int max, int step, bool orientation, int current);

	void SetSlider(float position);
	float GetSliderPosition();


};
}