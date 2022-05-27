#pragma once
#include <random>

namespace Engine {
	/*! \class Random
	* \brief classe representant un générateur de valeur aléatoire.
	*
	*/
	class Random {
	public:
		Random();
		int getIntInRange(int min, int max);
		double getDoubleInRange(double min, double max);
		float getFloatInRange(float min, float max);
	private:
		std::random_device seed;
		std::default_random_engine rnGen;
	};
}
