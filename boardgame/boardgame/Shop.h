#pragma once


#include<iostream>
#include<SFML/Graphics.hpp>
#include"Clicker.h"

class Shop
{
public:
	size_t boostx2 = 2;
	size_t boostx3 = 3;
	size_t boostx4 = 4;
	size_t boostx5 = 5;

	size_t pr_boostx2 = 50;
	size_t pr_boostx3 = 5000;
	size_t pr_boostx4 = 10000;
	size_t pr_boostx5 = 15000;

	Shop(sf::RenderWindow &window);

	int BuyItem(size_t clicks_made, int booster);
	int minusBuyItem(size_t clicks_made, int booster);
private:
	size_t counter = 0;
	sf::Font font;
	sf::Text text[5];
	std::string text_string[5];
};

