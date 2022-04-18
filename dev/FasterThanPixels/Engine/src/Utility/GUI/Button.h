#pragma once
#include"SFML/Graphics.hpp"
class Button {
public:
	sf::Sprite ButtonSprite; /*!< Sprite du bouton */
	sf::Text ButtonText;
	/**
	 * @def IsSpriteClicked
	 * @brief Si la souris a cliquer sur le sprite
	 * 	\param render : la fenetre
	*/
	bool IsSpriteClicked(sf::RenderWindow* render);
	bool IsText;
	Button();

	void InitButton(sf::Texture& Texture, sf::Vector2f pos);
	void InitButton(std::string Texte, sf::Vector2f pos, sf::Font& font, int CharacterSize);
};