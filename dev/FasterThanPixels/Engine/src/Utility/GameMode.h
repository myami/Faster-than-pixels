#pragma once
namespace Engine {
	class GameMode {
		virtual void OnGameModeStart() = 0;
		virtual void OnGameModeUpdate() = 0;
		virtual void OnGameModeEnd() = 0;

	};
	
}