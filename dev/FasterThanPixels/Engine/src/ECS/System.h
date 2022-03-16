#pragma once
namespace Engine {
	/*! \class System
	* \brief classe representant chaque Systeme qui sont lie au component actif
	*
	*/
	class System {
		/*!
		*  \brief RunSystem
		*
		*  Lance la sur tout les entite qui ont le component lie a se systeme
		*/
		virtual void RunSystem(Entity* Entity, float dt) = 0; // la boucle du systeme
		// pour chaque entite qui a le component lie a se systeme fait quelque chose
	};
}