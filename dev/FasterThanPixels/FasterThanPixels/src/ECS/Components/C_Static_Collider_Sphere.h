#pragma once
#include "Engine.h"
class C_Static_Collider_Sphere : public Engine::BlankComponent {
public:
	C_Static_Collider_Sphere();
	float Radius;
	sf::Vector2f Origin;
};