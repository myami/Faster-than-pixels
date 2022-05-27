#include "CheckBox.h"

bool CheckBox::IsSpriteClicked(sf::RenderWindow* render)
{
	return CheckBoxSprite.getGlobalBounds().contains(render->mapPixelToCoords(sf::Mouse::getPosition()));
}

CheckBox::CheckBox()
{
}

void CheckBox::InitCheckBox(sf::Texture& CheckBoxTexture, sf::Texture& CheckTexture, sf::Vector2f pos, double scale, bool isActive)
{
	State = isActive;
	CheckBoxSprite.setTexture(CheckBoxTexture);
	CheckBoxSprite.setOrigin(CheckBoxSprite.getGlobalBounds().width / 2.f, CheckBoxSprite.getGlobalBounds().height / 2.f);
	CheckBoxSprite.setPosition(pos.x, pos.y);
	CheckBoxSprite.setScale(scale, scale);

	CheckSprite.setTexture(CheckTexture);
	CheckSprite.setOrigin(CheckSprite.getGlobalBounds().width / 2.f, CheckSprite.getGlobalBounds().height / 2.f);
	CheckSprite.setPosition(pos.x, pos.y);
	CheckSprite.setScale(scale, scale);
}