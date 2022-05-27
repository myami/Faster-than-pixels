#include "MathF.h"

float Engine::DistanceBetweenVector(sf::Vector2f origin, sf::Vector2f destination)
{
	return sqrt(pow(destination.x - origin.x, 2) +
		pow(destination.y - origin.y, 2));
}

float Engine::AngleBetweenVector(sf::Vector2f origin, sf::Vector2f point1, sf::Vector2f point2)
{
	float a = DistanceBetweenVector(origin, point1);
	float b = DistanceBetweenVector(origin, point2);
	float c = DistanceBetweenVector(point1, point2);

	float cosangle = ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (a * b * 2));

	return acos(cosangle);
}

sf::Vector2f Engine::NormalizeVector(sf::Vector2f origin)
{
	float magnitude = sqrt(origin.x + origin.y);
	sf::Vector2f normalized = sf::Vector2f(origin.x, origin.y) / magnitude;
	return normalized;
}