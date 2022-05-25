#pragma once
#include <vector>

namespace Engine {
	/*! \class System
	* \brief classe representant chaque Systeme qui sont lie au component actif
	*
	*/
	class Entity;
	class System 
	{
		// entite pour laquelle on run le system
	public:
		System();
		std::vector <Entity*> EntityLoop;
		/*!
		*  \brief RunSystem
		*
		*  Run pour tout les entites qui ont decider d'etre dans se system
		*/
		virtual void RunSystem(float dt) = 0; // la boucle du systeme

		void RegisterSystem(Entity* ent);
		void RemoveEntity(Entity* ent);

		bool IsEntityInSystem(Entity* ent);
	

	};
}