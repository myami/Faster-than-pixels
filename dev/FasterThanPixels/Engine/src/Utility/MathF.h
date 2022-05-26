#pragma once
#include "SFML/Graphics.hpp"
namespace Engine {
	/*!
	*  \brief DistanceBetweenVector
	*
	*  Return la distance entre deux position
	* \param origin : Premiere position
	* \param destination : Seconde position
	* \return un float qui est la distance entre 2 objetz
	*/
	float DistanceBetweenVector(sf::Vector2f origin, sf::Vector2f destination);
	/*!
	*  \brief AngleBetweenVector
	*
	*  Return un angle entre deux vector
	* \param origin : Premiere position
	* \param point1 : Seconde position
	* \param point2 : troisième position
	* \return un float qui est un angle entre 3 points
	*/
	float AngleBetweenVector(sf::Vector2f origin, sf::Vector2f point1, sf::Vector2f point2);
	/*!
	*  \brief NormalizeVector
	*
	*  Return un vecteur normalise
	* \param origin : vecteur a normaliser
	* \return le vecteur normaliser
	*/
	sf::Vector2f NormalizeVector(sf::Vector2f origin);
}