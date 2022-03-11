#include "Random.h"

Engine::Random::Random() : rnGen(seed()) {
}

int Engine::Random::getIntInRange(int min, int max) {
	return std::uniform_int_distribution<int>(min, max - 1)(rnGen);
}

double Engine::Random::getDoubleInRange(double min, double max) {
	return std::uniform_real_distribution<double>(min, max)(rnGen);
}

float Engine::Random::getFloatInRange(float min, float max) {
	return std::uniform_real_distribution<float>(min, max)(rnGen);
}