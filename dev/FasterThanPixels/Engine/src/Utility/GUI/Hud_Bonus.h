#pragma once
#include"SFML/Graphics.hpp"

namespace Engine {

	class Hud_Bonus {
	
		sf::Font Font;
		sf::Vector2f PositionOrigin;
		sf::Sprite Icon;
		sf::Text CurrentValue;
		sf::Text MaxValue;
	public:


		Hud_Bonus();

		void InitHudBonus(sf::Texture& IconTexture, std::string BonusMaxValue, std::string BonusCurrentValue, sf::Font& FontAddress, int CharacterSize, sf::Vector2f PositionOrigin);

		sf::Sprite GetIcon();

		sf::Text GetMaxValue();

		void SetCurrentValue(std::string CurrentValue);
		sf::Text GetCurrentValue();
	};
}