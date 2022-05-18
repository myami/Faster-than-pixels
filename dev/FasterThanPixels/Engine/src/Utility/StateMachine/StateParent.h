#pragma once
namespace Engine {
	class StateParent {
	public:
		StateParent();
		virtual void Begin_Play() = 0;
		virtual void Tick() = 0;
		virtual void End_Play() = 0;
	};
}