#pragma once
#include "Engine.h"
class C_Transform : public Engine::Component {
	Engine::Vector2D Position;
	Engine::Vector2D Scale;
	Engine::Vector2D Rotation;
};