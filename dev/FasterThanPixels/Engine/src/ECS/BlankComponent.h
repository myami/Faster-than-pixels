#pragma once
#include "Component.h"
namespace Engine {

class BlankComponent : public Engine::Component {
public :
	void PrintName() override;
};
}