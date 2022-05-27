#pragma once
#include <SFML/Graphics.hpp>
namespace Engine {
	/*! \class Animation
	* \brief classe representant un sprite anim�
	*
	*/
	class Animation {
	public:

		/**
		*@param textureFileName: The file name for the spritesheet
		*@param spriteTimeLength: Time in seconds a singe sprite will stay on the screen.
		*@param numSprites: vector detailing how many sprites are on the spritesheet horizontally (x), and vertically (y).
		*/
		Animation();
		/**
		 * @def updateSprites
		 * @brief Update l'animation du sprite
		 * \param deltaTime : timer
		*/
		void updateSprites(float deltaTime);

		/**
		 * @def FrameToDraw
		 * @brief retourne le sprite de l'entit�e � afficher
		 * \return : une image
		*/
		sf::Sprite FrameToDraw();


		/**
		 * @def scaleSpriteSheet
		 * @brief Scale le spritesheet en fonction d'une dimension donn�e.
		 * \param numSprites les dimensions de la spritesheet.
		*/
		void scaleSpriteSheet(const sf::Vector2u& numSprites);

		std::vector<sf::Sprite> spritesToAnimate; /*!< Vecteur de Sprite � animer */
		int currentFrame; /*!< Frame courante dans le vecteur */
		float currentTime; /*!< */
		sf::Clock clock; /*!<  */

		float SPRITE_LENGTH_TIME; /*!< Temps pour parcourir le vecteur de Sprites */
		/**
		 * @def SetupAnimation
		 * @brief �tablis une animation pour un sprite.
		 * \param textures Le Spritesheet.
		 * \param DureeAnimation temps pour faire l'animation.
		 * \param numSprites les dimensions de la spritesheet.
		 * \param InitialPosition Position du sprite.
		*/
		void SetupAnimation(sf::Texture& textures, float DureeAnimation, const sf::Vector2u& numSprites, sf::Vector2f InitialPosition);
		/**
		 * @def MoveSprite
		 * @brief D�place le sprite.
		 * \param direction vecteur de direction pour d�placer le sprite.
		*/
		void MoveSprite(const sf::Vector2f& direction);
		/**
		 * @def ScaleAnimation
		 * @brief Agrandi ou r�tr�ci le sprite.
		 * \param sc Scalaire.
		*/
		void ScaleAnimation(float sc);
	};
}