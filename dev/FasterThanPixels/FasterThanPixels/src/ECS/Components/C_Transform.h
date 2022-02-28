#pragma once
#include "Engine.h"
/*! \class C_Transform
* \brief classe representant le component Transform, Si l'entite a ce component, cela veux dire que il a des positions et peux apparaitre dans le jeu
*
*/
class C_Transform : public Engine::Component {
public:
	Engine::Vector2D Position;  /*!< Position de l'entite */
	Engine::Vector2D Scale;  /*!< Scale de l'entite */
	Engine::Vector2D Rotation;  /*!< Rotation de l'entite */
	Engine::Vector2D Direction;  /*!< Direction de l'entite */

};