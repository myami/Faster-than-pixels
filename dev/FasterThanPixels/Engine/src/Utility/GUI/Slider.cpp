#include "Slider.h"

Engine::Slider::Slider()
{
}

void Engine::Slider::InitSlider(int min, int max, int step, bool orientation, int current)
{
	this->min = min;
	this->max = max;
	this->step = step;
	this->orientation = orientation;
	SetSlider(current);
}

void Engine::Slider::SetSlider(float position)
{
	this->CurrentPosition = position;

}

float Engine::Slider::GetSliderPosition()
{
	return CurrentPosition;
}



