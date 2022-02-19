#include "GameManager.h"

void Engine::GameManager::ResizeView(sf::Event event)
{
	sf::FloatRect visiblearea(0, 0, event.size.width, event.size.height);
	Windows->setView(sf::View(visiblearea));
}
