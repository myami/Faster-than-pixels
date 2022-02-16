#pragma once
#include "Engine.h"
// Joueur et IA
class C_MouvementActif : public Engine::Component {
public:
	C_MouvementActif();
	Engine::Vector2D Direction;
	

};