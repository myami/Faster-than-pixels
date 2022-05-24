#pragma once
#include "Component.h"
namespace Engine {

class BlankComponent : public Engine::Component {
public :
	BlankComponent(std::string na);
	void PrintName() override;
};
}