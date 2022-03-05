#include "Button.h"

bool Button::IsSpriteClicked( sf::RenderWindow* render)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return ButtonSprite.getGlobalBounds().contains(render->mapPixelToCoords(sf::Mouse::getPosition()));
    }
}

Button::Button()
{
}


