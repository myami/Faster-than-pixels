#include "System.h"
#include <vector>

Engine::System::System()
{
}

void Engine::System::RegisterSystem(Entity* ent)
{
	EntityLoop.push_back(ent);
}

void Engine::System::RemoveEntity(Entity* ent)
{
	EntityLoop.erase(std::remove(EntityLoop.begin(), EntityLoop.end(), ent), EntityLoop.end());
}

bool Engine::System::IsEntityInSystem(Entity* ent)
{
	for (auto const& entity : EntityLoop) {
		if (entity == ent) {
			return true;
		}
	}
	return false;
}