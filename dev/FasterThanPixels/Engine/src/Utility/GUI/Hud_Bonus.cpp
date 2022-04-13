#include "Hud_Bonus.h"

Engine::Hud_Bonus::Hud_Bonus()
{
}

Engine::Hud_Bonus::Hud_Bonus(sf::Texture IconTexture, std::string BonusMaxValue, std::string BonusCurrentValue, sf::Font FontAddress, int CharacterSize, sf::Vector2f PositionOrigin)
{
	this->PositionOrigin = PositionOrigin;
	Icon.setTexture(IconTexture);
	Icon.setOrigin(Icon.getGlobalBounds().width / 2.f, Icon.getGlobalBounds().height / 2.f);
	Icon.setPosition(PositionOrigin.x, PositionOrigin.y);

	MaxValue.setFont(FontAddress);
	MaxValue.setCharacterSize(CharacterSize);
	MaxValue.setOrigin(MaxValue.getGlobalBounds().width / 2.f, MaxValue.getGlobalBounds().height / 2.f);
	MaxValue.setPosition(PositionOrigin.x + 20, PositionOrigin.y - 10);
	MaxValue.setString("/" + BonusMaxValue);

	CurrentValue.setFont(FontAddress);
	CurrentValue.setCharacterSize(CharacterSize);
	CurrentValue.setOrigin(CurrentValue.getGlobalBounds().width / 2.f, CurrentValue.getGlobalBounds().height / 2.f);
	CurrentValue.setPosition(PositionOrigin.x + 40, PositionOrigin.y - 10);
	CurrentValue.setString(BonusCurrentValue);

}

sf::Sprite Engine::Hud_Bonus::GetIcon()
{
	return Icon;
}

sf::Text Engine::Hud_Bonus::GetMaxValue()
{
	return MaxValue;
}

sf::Text Engine::Hud_Bonus::GetCurrentValue()
{
	return CurrentValue;
}

void Engine::Hud_Bonus::SetCurrentValue(std::string CurrentValue)
{
	this->CurrentValue.setString(CurrentValue);
}


