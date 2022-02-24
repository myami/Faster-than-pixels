#pragma once
#include "Vector2D.h"
#include <vector>
namespace Engine {
	class Path {
	public:
		std::vector<Vector2D> nodes;
		void AddNodes(Vector2D newpos);
		std::vector<Vector2D> Getnodes();
	};
}