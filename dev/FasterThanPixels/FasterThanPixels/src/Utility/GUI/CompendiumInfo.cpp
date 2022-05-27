#include "CompendiumInfo.h"
#include <iostream>

CompendiumInfo::CompendiumInfo() {};

void CompendiumInfo::InitCompendiumInfo(bool isEnnemy, sf::Font& Font, int size, std::string Titre, sf::Texture& Image, std::string DamageValue, std::string ShieldValue, std::string LifeValue, std::string Description, sf::Vector2f pos, double scale)
{
	m_Titre.setFont(Font);
	m_Titre.setString(Titre);
	m_Titre.setOrigin(m_Titre.getGlobalBounds().width / 2.f, m_Titre.getGlobalBounds().height / 2.f);
	m_Titre.setPosition(pos);
	m_Titre.move(300.f, -150.f);
	m_Titre.setCharacterSize(size + 5);

	m_Image.setTexture(Image);
	m_Image.setPosition(pos);
	m_Image.setOrigin(m_Image.getGlobalBounds().width / 2.f, m_Image.getGlobalBounds().height / 2.f);
	m_Image.move(50.f, -50.f);
	m_Image.scale(scale, scale);

	if (isEnnemy) {
		m_Damage.setString("Damage : " + DamageValue);
		m_Damage.setPosition(pos);
		m_Damage.setFont(Font);
		m_Damage.move(150.f, -100.f);
		m_Damage.setCharacterSize(size);

		m_Shield.setString("Shield : " + ShieldValue);
		m_Shield.setPosition(pos);
		m_Shield.setFont(Font);
		m_Shield.move(150.f, -75.f);
		m_Shield.setCharacterSize(size);

		m_Life.setString("Life : " + LifeValue);
		m_Life.setPosition(pos);
		m_Life.setFont(Font);
		m_Life.move(150.f, -50.f);
		m_Life.setCharacterSize(size);
	}

	m_Description.setFont(Font);
	m_Description.setString(Description);
	m_Description.setPosition(pos);
	m_Description.setCharacterSize(size);
	m_Description.move(350.f, -100.f);
}