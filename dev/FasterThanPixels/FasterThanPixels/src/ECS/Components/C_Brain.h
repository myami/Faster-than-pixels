#pragma once
// logique de l'ia
#include "Engine.h"
/*! \class C_Brain
* \brief classe representant le component Brain, Si l'entite l'a cela lui permait de calculer son vector de direction par rapport a une autre entite
*
*/
class C_Brain : public Engine::Component {
	/*!
	*  \brief FindEntity
	*
	*  Return un vecteur de direction vers l'entite selectionner
	* \param entite : Entite a suivre
	* \return le vecteur de direction
	*/
	Engine::Vector2D FindEntity(Engine::Entity entite);
	/*!
	*  \brief ObstacleOnPath
	*
	*  si il y a un obstacle devant l'entite
	* \return true si il y a un obstacle devant l'entite
	*/
	bool ObstacleOnPath(); 
	/*!
	*  \brief FollowPath
	*
	*  Modifie le component transform pour modifier le vector de direction
	*/
	void FollowPath(); 
	/*!
	*  \brief Wander
	*
	*  ajoute un peux de random pour que les mouvements de l'enemie sois plus naturel et moins straigt forward
	* \return un vector de direction
	*/
	Engine::Vector2D Wander(); 
	/*!
	*  \brief Pursuit
	*
	* essaye de predire ou l'entite qu il suis va etre en gettant sont vecteur de direction
	* \return un vector de position
	*/
	Engine::Vector2D Pursuit(); 
	/*!
	*  \brief AvoidObstacle
	*
	* si il y a un obstacle , calcule le meilleur chemin pour l'eviter
	* \return un vector de direction
	*/
	Engine::Vector2D AvoidObstacle(); 
	/*!
	*  \brief FindMostThreateningObstacle
	*
	* Trouve l'obstacle le plus dangereux 
	* \return une entite a eviter
	*/
	Engine::Entity FindMostThreateningObstacle(); 
	/*!
	*  \brief GetNeighboorAhead
	*
	* si tu suis le vaiseau mere avec 50 autre vaiseau, savoir lequel est devant toi pour le suivre lui en chaine
	* \return une entite a suivre
	*/
	Engine::Entity GetNeighboorAhead(); 

	int CurrentNode;  /*!< Node de l'entite qu'il va en direction */
	Engine::Path Path;  /*!< La classe Path */
	bool FollowLeader;  /*!< Si il suis un chef ou pas (pour se suivre proprement en chaine ou pas) */


};