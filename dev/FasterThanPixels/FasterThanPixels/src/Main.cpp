#include "Engine.h"
#include "Factory/FTP_GameManager.h"

int main() {
	FTP_GameManager game;
	game.Game_Init();
	game.GameLoop();
}