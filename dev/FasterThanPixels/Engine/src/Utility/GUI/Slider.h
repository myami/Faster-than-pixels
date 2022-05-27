#pragma once
#include "SFML/Graphics.hpp"
namespace Engine {
	class Slider {
		float CurrentPosition; /*!< Position du slider */
	public:
		sf::Sprite Background; /*!< Sprite du background */
		sf::Sprite SliderBar; /*!< Sprite du slider */
		Slider();
		bool orientation; // false == horizontal, true = vertical
			/**
		 * @def SetSlider
		 * @brief transforme la valeur en une valeur entre 0 et 1. on prend en entree une valeur entre 0 et 100 et on la divise pour etre entre 0 et 1
		 * 	\param position : doit etre un entier entre 0 et 100
		*/
		void InitSlider(int min, int max, int step, bool orientation, int current);
		/**
		 * @def SetSlider
		 * @brief transforme la valeur en une valeur entre 0 et 1. on prend en entree une valeur entre 0 et 100 et on la divise pour etre entre 0 et 1
		 * 	\param position : doit etre un entier entre 0 et 100
		*/
		void SetSlider(int position);
		/**
	 * @def GetSliderPosition
	 * @brief retourne la position du slider entre 0 et 100
	*/
		float GetSliderPosition();

		bool IsSpriteClicked(sf::RenderWindow* render);
	};
}