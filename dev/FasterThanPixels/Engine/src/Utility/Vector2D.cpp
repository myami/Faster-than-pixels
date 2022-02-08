#include "Vector2D.h"

Engine::Vector2D::Vector2D()
{
	x, y = 0;
}

Engine::Vector2D::Vector2D(float xthis, float ythis)
{
	this->x = xthis;
	this->y = ythis;

}

bool Engine::Vector2D::operator==(const Vector2D& other) const
{
	return (x == other.x) && (y == other.y);
}

Engine::Vector2D Engine::Vector2D::operator+(const Vector2D& other) const
{
	return Vector2D(x + other.x, y + other.y);
} 

Engine::Vector2D Engine::Vector2D::operator*(const float& val) const
{
	return Vector2D(x * val, y*val);
}

void Engine::Vector2D::operator+=(const Vector2D& other)
{
	x += other.x;
	y += other.y;
}

Engine::Vector2D Engine::Vector2D::operator-(const Vector2D& other) const
{
	return Vector2D(x - other.x, y - other.y);
}

void Engine::Vector2D::operator-=(const Vector2D& other)
{
	this->x -= other.x;
	this->y -= other.y;
}


