#pragma once
#include "Vector2D.h"
namespace Engine {
	/*!
	*  \brief DistanceBetweenVector
	*
	*  Return la distance entre deux position
	* \param origin : Premiere position
	* \param destination : Seconde position
	* \return un float qui est la distance entre 2 objet
	*/
	float DistanceBetweenVector(Engine::Vector2D origin, Engine::Vector2D destination);
	/*!
	*  \brief AngleBetweenVector
	*
	*  Return un angle entre deux vector
	* \param origin : Premiere position
	* \param destination : Seconde position
	* \return un float qui est un angle entre 2 objet
	*/
	float AngleBetweenVector(Engine::Vector2D origin, Engine::Vector2D destination);
	/*!
	*  \brief NormalizeVector
	*
	*  Return un vecteur normalise
	* \param origin : vecteur a normaliser
	* \return le vecteur normaliser
	*/
	Vector2D NormalizeVector(Vector2D origin);
}