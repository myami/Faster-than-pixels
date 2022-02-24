#pragma once
#pragma once
#include "Engine.h"
#include "box2d/box2d.h"
// Asteroid 
class C_MouvementPassif : public Engine::Component {
public:
	b2BodyDef def;
	b2Body body;
	b2Fixture fixture;
	b2PolygonShape collider;
	
};