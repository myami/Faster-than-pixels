#include "Animation.h"
#include <iostream>
#include "Random.h"
// inspirer de https://github.com/darienmiller88/Animation-SFML

Engine::Animation::Animation()
{
}

void Engine::Animation::updateSprites(float deltaTime) {
	currentTime = clock.getElapsedTime().asSeconds();

	if (currentTime >= SPRITE_LENGTH_TIME) {
		currentTime -= SPRITE_LENGTH_TIME;
		clock.restart();
		if (++currentFrame >= spritesToAnimate.size())
			currentFrame = 0;
	}

	//spritesToAnimate[currentFrame].move(direction);
}

sf::Sprite Engine::Animation::FrameToDraw()
{
	return spritesToAnimate[currentFrame];
}

void Engine::Animation::scaleSpriteSheet(const sf::Vector2u& numSprites) {
	if (spritesToAnimate[currentFrame].getTexture()->getSize().x % numSprites.x != 0 or spritesToAnimate[currentFrame].getTexture()->getSize().y % numSprites.y != 0) {
		//If the width and height of the sprite sheet aren't perfectly disivible the number of sprites, cast the result
		//to an int, and multiply the result by the number of sprites. This will give us the exact window width and
		//height needed to resize the spritesheet to allow it to be divisible by the number of sprites.
		int newSpriteSheetWidth = (spritesToAnimate[currentFrame].getTexture()->getSize().x / numSprites.x) * numSprites.x;
		int newSpriteSheetHeight = (spritesToAnimate[currentFrame].getTexture()->getSize().y / numSprites.y) * numSprites.y;

		float xScale = newSpriteSheetWidth / spritesToAnimate[currentFrame].getTexture()->getSize().x;
		float yScale = newSpriteSheetHeight / spritesToAnimate[currentFrame].getTexture()->getSize().y;
	}
}

void Engine::Animation::SetupAnimation(sf::Texture& textures, float DureeAnimation, const sf::Vector2u& numSprites, sf::Vector2f InitialPosition)
{
	//spriteTexture = textures;
	SPRITE_LENGTH_TIME = DureeAnimation;
	currentTime = 0.f;
	currentFrame = 0;

	sf::Vector2u spriteSize;

	//On the sprite sheet image that was read into "spriteTexture", it is a numSprites.x by numSprites.y sheet, so to get the
	//length and width of each sprite, I have to divide the length and width of the sprite sheet by the number of sprites
	//on each dimension.
	spriteSize.x = textures.getSize().x / numSprites.x;
	spriteSize.y = textures.getSize().y / numSprites.y;


	for (int y = 0; y < numSprites.y; y++) {
		for (int x = 0; x < numSprites.x; x++) {
			//Using the sprite sheet, we will slice a rectangle into each of the sprites, and push it into the vector
			//of sprites, going row by row, left to right.
			spritesToAnimate.push_back(sf::Sprite(textures, sf::IntRect(spriteSize.x * x,
				spriteSize.y * y, spriteSize.x, spriteSize.y)));
			spritesToAnimate.back().setPosition(InitialPosition);
		}
	}
}

void Engine::Animation::MoveSprite(const sf::Vector2f& direction)
{
	for (auto& sprite : spritesToAnimate)
		sprite.move(direction);
}

void Engine::Animation::ScaleAnimation(float sc)
{
	for (auto& sprite : spritesToAnimate)
		sprite.setScale({ sc,sc });
}