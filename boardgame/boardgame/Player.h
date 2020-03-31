#pragma once

#include<SFML/Graphics.hpp>
class Player
{
private:
	sf::Vector2f Position;
	sf::Sprite Sprite;
	sf::Texture Texture;
	// לב קעמ עמ וש¸
public:
	Player();
	sf::Sprite getSprite();
	void update(float elapsedTime);
};

