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
		/*!
		 *  \brief Ajoute une entite dans le systeme
		 *
		 *	Enregistre dans EntityLoop une entite
		 *  \param Entity* ent : l'entite
		 */

		void RegisterSystem(Entity* ent);
		/*!
		 *  \brief Supprime une entite du systeme
		 *
		 *	Supprime une entite du systeme
		 *  \param Entity* ent : l'entite
		 */
		void RemoveEntity(Entity* ent);
		/*!
		 *  \brief Check que l'entite est dans le system
		 *
		 *	Check que l'entite est dans le system
		 *  \param Entity* ent : l'entite
		 */

		bool IsEntityInSystem(Entity* ent);
	};
}