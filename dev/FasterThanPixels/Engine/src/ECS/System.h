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
		*  \brief Run les entites
		*
		*  Run pour tout les entites qui sont dotées de ce système
		*/

		virtual void RunSystem(float dt) = 0;
		/*!
		 *  \brief Enregistre dans EntityLoop une entite
		 *
		 *  \param Entity* ent : l'entite
		 */

		void RegisterSystem(Entity* ent);
		/*!
		 *  \brief Supprime une entite du système
		 *
		 *  \param Entity* ent : l'entite
		 */

		void RemoveEntity(Entity* ent);
		/*!
		 *  \brief Check que l'entite est dans le system
		 *
		 *  \param Entity* ent : l'entite
		 */

		bool IsEntityInSystem(Entity* ent);
	};
}