#include "Button.h"

bool Button::IsSpriteClicked( sf::RenderWindow* render)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!IsText)
            return ButtonSprite.getGlobalBounds().contains(render->mapPixelToCoords(sf::Mouse::getPosition()));
        else
            return ButtonText.getGlobalBounds().contains(render->mapPixelToCoords(sf::Mouse::getPosition()));
    }
}

Button::Button()
{
}

void Button::InitButton(sf::Texture& Texture, sf::Vector2f pos)
{
    ButtonSprite.setTexture(Texture);
    ButtonSprite.setOrigin(ButtonSprite.getGlobalBounds().width / 2.f, ButtonSprite.getGlobalBounds().height / 2.f);
    ButtonSprite.setPosition(pos.x, pos.y);
    //ButtonSprite.move(sf::Vector2(-ButtonSprite.getGlobalBounds().width / 2.f, -ButtonSprite.getGlobalBounds().height / 2.f));
    IsText = false;
}

void Button::InitButton(std::string Texte, sf::Vector2f pos, sf::Font& font, int CharacterSize)
{
    IsText = true;
    ButtonText.setFont(font);
    ButtonText.setCharacterSize(CharacterSize);
    ButtonText.setString(Texte);
    ButtonText.setOrigin(ButtonText.getGlobalBounds().width / 2.f, ButtonText.getGlobalBounds().height / 2.f);
    ButtonText.setPosition(pos.x, pos.y);
}


