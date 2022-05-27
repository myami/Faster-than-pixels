#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>
#include <iostream>

#define DELETE_KEY 8 /*!< Touche delete */
#define ENTER_KEY 13 /*!< Touche entree */
#define ESCAPE_KEY 27 /*!< Touche echap */
class Input {
	void DeleteLastChar();
public:
	Input();
	Input(int size, bool sel);
	sf::Text textbox; /*!< Zone de texte sfml qui apparait */
	std::ostringstream text; /*!< Texte brut */
	sf::Sprite BackgroundTexture; /*!< Sprite en arriere de l'input */
	bool isSelected = false; /*!<Si on a cliqué sur le text */
	bool hasLimit = false; /*!< Si il y a une limite de charactere */
	bool isCrypted = false; /*!< Si on ne dois pas afficher dans sfml le contenu */
	int limit; /*!< nombre de char si il y a une limite */
	/**
	 * @def InputLogic
	 * @brief Gere la logique quand il recois un char
	 * 	\param chartyped : lettre
	*/
	void InputLogic(int chartyped);
	/**
	 * @def SetSelected
	 * @brief si sa doit ecrire dedans
	 * \param sel : true/false
	*/
	void SetSelected(bool sel);
	/**
	 * @def GetText
	 * @brief return le text
	*/
	std::string GetText();
	/**
	 * @def TypedOn
	 * @brief event de sfml
	 * \param event : event de sfml
	*/
	void TypedOn(sf::Event event);
	/**
	 * @def IsInputClicked
	 * @brief Si on clique sur le input
	 * \param render : fenetre
	*/
	bool IsInputClicked(sf::RenderWindow* render);
	/**
	 * @def SetPosition
	 * @brief Set la position et le texte
	 * \param string : text
	 * \param sf::Vector2f : pos
	*/
	void SetPosition(std::string text, sf::Vector2f pos);
};
