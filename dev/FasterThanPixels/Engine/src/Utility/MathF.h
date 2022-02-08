#pragma once
#include "Vector2D.h"
namespace Engine {
	float DistanceBetweenVector(Engine::Vector2D origin, Engine::Vector2D destination);
	float AngleBetweenVector(Engine::Vector2D origin, Engine::Vector2D destination);
	Vector2D NormalizeVector(Vector2D origin);
}