#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include<iostream>
#include "Engine.h"

class Clicker
{
public:
	Clicker() {}
	Clicker(sf::RenderWindow &window);
	void isClicked(sf::RenderWindow &window);

private:
	sf::Sprite coin;
	sf::Sprite coin2;
	sf::Texture coin_texture2;
	sf::Texture coin_texture;
	sf::Clock clock;
	sf::Time timer;
protected:
	size_t clicks_made = 0;
	size_t clicks_per_sec = 0;
	int booster = 1;
};

