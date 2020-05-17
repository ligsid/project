#pragma once


#include<iostream>
#include<SFML/Graphics.hpp>
#include"Clicker.h"

class Shop
{
public:
	size_t boost[5] = { 2,3,4,5,0 };

	size_t pr_boost[5] = { 50, 5000, 10000, 150000, 0};

	Shop(sf::RenderWindow &window);
	int WichGoingToPressed(sf::RenderWindow &window);
	void shop_draw(sf::RenderWindow &window);
	int BuyItem(size_t clicks_made, int booster, int numboost);
	int minusBuyItem(size_t clicks_made, int booster, int numboost);
private:
	size_t counter = 0;
	sf::Font font;
	sf::Text text[5];
	std::string text_string[5];
};

