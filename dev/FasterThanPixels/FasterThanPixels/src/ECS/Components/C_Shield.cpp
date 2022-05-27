#include "C_Shield.h"

C_Shield::C_Shield() : Engine::BlankComponent("Shield")
{
	ShieldClock.restart();
}