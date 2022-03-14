#pragma once
#include "Engine.h"
#include "SFML/Graphics.hpp"
/*! \class C_Transform
* \brief classe representant le component Transform, Si l'entite a ce component, cela veux dire que il a des positions et peux apparaitre dans le jeu
*
*/
class C_Transform : public Engine::Component {
public:
	sf::Vector2f Direction;  /*!< Direction de l'entite */

};