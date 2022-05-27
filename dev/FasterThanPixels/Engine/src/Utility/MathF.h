#pragma once
#include "SFML/Graphics.hpp"

namespace Engine {
	/*!
	*  @def DistanceBetweenVector
	*
	*  Return la distance entre deux position de type Vector2f
	* \param origin : Premiere position
	* \param destination : Seconde position
	* \return un float qui est la distance entre 2 objetz
	*/
	float DistanceBetweenVector(sf::Vector2f origin, sf::Vector2f destination);
	/*!
	*  @def AngleBetweenVector
	*
	*  Return un angle entre trois points de type Vector2f
	* \param origin : Premiere position
	* \param point1 : Seconde position
	* \param point2 : troisième position
	* \return un float qui est un angle entre 3 points
	*/
	float AngleBetweenVector(sf::Vector2f origin, sf::Vector2f point1, sf::Vector2f point2);
	/*!
	*  @def NormalizeVector
	*
	*  Return un vector2f normalise
	* \param origin : vecteur à normaliser
	* \return le vecteur normalisé
	*/
	sf::Vector2f NormalizeVector(sf::Vector2f origin);
}