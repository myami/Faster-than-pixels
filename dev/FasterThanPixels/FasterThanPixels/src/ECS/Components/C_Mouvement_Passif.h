#pragma once
#pragma once
#include "Engine.h"
#include "box2d/box2d.h"
/*! \class C_MouvementPassif
* \brief classe representant le component MouvementPassif, Si l'entite l'a cela lui permait de recevori des inputs de la simulation de physic
*
*/
class C_MouvementPassif : public Engine::BlankComponent {
public:
	C_MouvementPassif();
	/*b2BodyDef def;  /*!< Box2D TODO */
	/*b2Body body; /*!< Box2D TODO */
	/*b2Fixture fixture; /*!< Box2D TODO */
	/*b2PolygonShape collider; /*!< Box2D TODO */
};