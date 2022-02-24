#pragma once
// logique de l'ia
#include "Engine.h"
class C_Brain : public Engine::Component {
	Engine::Vector2D FindEntity(Engine::Entity); // trouve la position de la targer (current vector + direction)
	bool ObstacleOnPath(); // check si il y a des obstacles dans le chemin
	void FollowPath(); // fait avancer le vaiseau
	Engine::Vector2D Wander(); // ajoute un peux de random pour que les mouvements de l'enemie sois plus naturel et moins straigt forward
	Engine::Vector2D Pursuit(); // essaye de predire ou le joueur va etre
	Engine::Vector2D AvoidObstacle(); // si il y a un obstacle , calcule le meilleur chemin pour l'eviter
	Engine::Entity FindMostThreateningObstacle(); // Trouve l'obstacle le plus dangereux 
	Engine::Entity GetNeighboorAhead(); // si tu suis le vaiseau mere avec 50 autre vaiseau, savoir lequel est devant toi pour le suivre lui en chaine

	int CurrentNode;
	Engine::Path Path;
	bool FollowLeader;


};