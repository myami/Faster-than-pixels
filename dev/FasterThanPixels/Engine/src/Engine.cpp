#include "Engine.h"
#include <iostream>
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"
namespace Engine {
	void PrintMessage()
	{
		std::cout << "Hello";
	}

	void ShowWindows() {
        nlohmann::json j;

        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
	}
}