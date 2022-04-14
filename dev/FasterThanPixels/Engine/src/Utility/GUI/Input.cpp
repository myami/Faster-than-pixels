#include "Input.h"
Input::Input()
{
}
Input::Input(int size, bool sel)
{
	isSelected = sel;
	if (sel) {
		textbox.setString("_");
	}
	else {
		textbox.setString("");
	}

}

void Input::InputLogic(int chartyped)
{
	if (chartyped != DELETE_KEY && chartyped != ENTER_KEY && chartyped != ESCAPE_KEY) {
		text << static_cast<char>(chartyped);
	}
	else if (chartyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			DeleteLastChar();
		}
	}
	else if (isSelected && chartyped == ENTER_KEY || chartyped == ESCAPE_KEY)
	{
		SetSelected(false);
	}
	if (!isCrypted) {
	textbox.setString(text.str() + "_");

	}
	else {
		std::string star;
		for (size_t i = 0; i < text.str().length(); i++)
		{
			star += "*";
		}
		textbox.setString(star + "_");

	}
}

void Input::SetSelected(bool sel)
{
	isSelected = sel;
	if (!sel) {
		if (!isCrypted) {
		textbox.setString("");
		textbox.setString(text.str());

		}
		else {
			std::string star;
			for (size_t i = 0; i < text.str().length(); i++)
			{
				star += "*";
			}
			textbox.setString("");
			textbox.setString(star);
		}

	}
	else {
		if (!isCrypted) {
			textbox.setString("");
			textbox.setString(text.str());

		}
		else {
			std::string star;
			for (size_t i = 0; i < text.str().length(); i++)
			{
				star += "*";
			}
			textbox.setString("");
			textbox.setString(star + "_");
		}

	}
}

std::string Input::GetText()
{
	return text.str();
}

void Input::TypedOn(sf::Event event)
{
	if (isSelected) 
	{
		int charTypes = event.text.unicode;
		if (charTypes < 128) 
		{
			if (hasLimit) 
			{
				if (text.str().length() <= limit) 
				{
					InputLogic(charTypes);
				}
				else if (text.str().length() > limit && charTypes == DELETE_KEY) 
				{
					{
						DeleteLastChar();
					}
				}
			}
			else 
			{
				InputLogic(charTypes);
			}
		}
	}
}

bool Input::IsInputClicked(sf::RenderWindow* render)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return BackgroundTexture.getGlobalBounds().contains(render->mapPixelToCoords(sf::Mouse::getPosition()));
	}
}

void Input::SetPosition(std::string text, sf::Vector2f pos)
{
	textbox.setPosition(pos.x, pos.y);
	textbox.move(sf::Vector2(- textbox.getGlobalBounds().width / 2.f, - textbox.getGlobalBounds().height / 2.f));
	BackgroundTexture.setPosition(pos.x, pos.y);
	textbox.setString(text);
}

void Input::DeleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (size_t i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str());
}
