#include "Slider.h"
#include <iostream>
Engine::Slider::Slider()
{
}

void Engine::Slider::InitSlider(int min, int max, int step, bool orientation, int current)
{
	this->orientation = orientation;
	SetSlider(current);
}

void Engine::Slider::SetSlider(int position)
{
	this->CurrentPosition = std::clamp((float)position, (float)0, (float)100) / 100;
	if (orientation) {
		SliderBar.setScale(sf::Vector2f(SliderBar.getScale().x, this->CurrentPosition));
	}
	else {
		SliderBar.setScale(sf::Vector2f(this->CurrentPosition,SliderBar.getScale().y));

	}

}

float Engine::Slider::GetSliderPosition()
{
	return CurrentPosition * 100;
}



