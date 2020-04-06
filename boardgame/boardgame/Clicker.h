#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include<iostream>
#include "Engine.h"

class Clicker
{
public:
	Clicker(sf::RenderWindow &window);
	void isClicked(sf::RenderWindow &window);

private:
	sf::Clock Clock;
	sf::Sprite coin;
	sf::Texture coin_texture2;
	sf::Texture coin_texture;
	size_t clicks_made = 0;
	std::vector<sf::IntRect> frames{
		sf::IntRect(418, 484, 16, 16),
		sf::IntRect(788, 912, 16, 16)
	};
};

