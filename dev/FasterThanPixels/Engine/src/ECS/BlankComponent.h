#pragma once
#include "Component.h"
namespace Engine {
	/*!
	 * \file BlankComponent.h
	 * \brief Enfant de la classe Component, utiliser comme classe parente dans le second projet
	 * \version 0.1
	 */

class BlankComponent : public Engine::Component {
public :
	BlankComponent(std::string na);
	void PrintName() override;
};
}