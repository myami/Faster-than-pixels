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
	* \param destination : Seconde position
	* \return un float qui est un angle entre 2 objet
	*/
	float AngleBetweenVector(sf::Vector2f origin, sf::Vector2f destination);
	/*!
	*  \brief NormalizeVector
	*
	*  Return un vecteur normalise
	* \param origin : vecteur a normaliser
	* \return le vecteur normaliser
	*/
	sf::Vector2f NormalizeVector(sf::Vector2f origin);
}