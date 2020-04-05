#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include<iostream>

class Clicker
{
public:
	Clicker() {}
	void check_coin(float dt);
	
private:
	sf::Clock timer;
	sf::Time reset_timer;
	size_t clicks_made;
	
};

