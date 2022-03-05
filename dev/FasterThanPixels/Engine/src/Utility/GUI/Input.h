#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>
#include <iostream>

// sources : https://www.youtube.com/watch?v=T31MoLJws4U&t=1860s&ab_channel=TermSpar mais modifier pour que sa marche de notre maniere
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
class Input {
	void DeleteLastChar();
public:
	Input();
	Input(int size,bool sel);
	sf::Text textbox;
	std::ostringstream text;
	sf::Sprite BackgroundTexture;
	bool isSelected = false;
	bool hasLimit = false;
	bool isCrypted = false;
	int limit;
	void InputLogic(int chartyped);
	void SetSelected(bool sel);
	std::string GetText();
	void TypedOn(sf::Event event);
	bool IsInputClicked(sf::RenderWindow* render);


};
