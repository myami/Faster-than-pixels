#pragma once
#include"SFML/Graphics.hpp"

class CompendiumInfo {
public:
	bool isEnnemy;
	sf::Text m_Titre;
	sf::Sprite m_Image;
	sf::Text m_Damage;
	sf::Text m_Shield;
	sf::Text m_Life;
	sf::Text m_Description;
	CompendiumInfo();
	void InitCompendiumInfo(bool isEnnemy, sf::Font& font, int size, std::string Titre, sf::Texture& Image, std::string DamageValue, std::string ShieldValue, std::string LifeValue, std::string Description, sf::Vector2f pos, double scale = 0.25);
};