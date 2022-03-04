#include "Engine.h"
#include "Factory/FTP_GameManager.h"
#include "SFML/Graphics.hpp"

int main() {
	FTP_GameManager game;
	game.Game_Init("Faster than Pixels", "Cinematique");
	game.GameLoop();
}