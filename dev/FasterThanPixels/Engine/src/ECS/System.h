#pragma once
namespace Engine {
	class System {
		virtual void RunSystem() = 0; // la boucle du systeme
		// pour chaque entite qui a le component lie a se systeme fait quelque chose
	};
}