#pragma once
// inventaire
#include "Engine.h"
#include "C_Pickup.h"
class C_ItemList : public Engine::Component {
	std::map<int, C_Pickup> Inventory;
};