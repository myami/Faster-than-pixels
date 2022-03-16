#pragma once
#include "Engine.h"
class C_Kynematic_Collider_Sphere : public Engine::BlankComponent {
public:
	float Radius;
	sf::Vector2f Origin;
};