#pragma once
#include "Engine.h"
class C_Animated_Render : public Engine::BlankComponent {
public:
	C_Animated_Render();
	Engine::Animation AnimatedSprite;
};