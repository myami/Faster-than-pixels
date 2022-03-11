#pragma once
#include <SFML/Graphics.hpp>
namespace Engine {


class Animation { // https://github.com/darienmiller88/Animation-SFML
public:

	/**
	*@param textureFileName: The file name for the spritesheet
	*@param spriteTimeLength: Time in seconds a singe sprite will stay on the screen.
	*@param numSprites: vector detailing how many sprites are on the spritesheet horizontally (x), and vertically (y).
	*/
	Animation();
	void updateSprites(float deltaTime);

	sf::Sprite FrameToDraw();

	void scaleSpriteSheet(const sf::Vector2u& numSprites);

	sf::Texture spriteTexture;
	std::vector<sf::Sprite> spritesToAnimate;
	int currentFrame;
	float currentTime;
	sf::Clock clock;

	//Time in seconds a singe sprite will stay on the screen.
	float SPRITE_LENGTH_TIME;

	void SetupAnimation(sf::Texture textures, float DureeAnimation,const sf::Vector2u& numSprites,sf::Vector2f InitialPosition);
	void MoveSprite(const sf::Vector2f& direction);

	void ScaleAnimation(float sc);
};

}