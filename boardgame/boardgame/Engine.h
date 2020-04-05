#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include "Clicker.h"



class Engine
{
private:
	sf::RenderWindow window;
	sf::Clock timer;
	sf::Time updateTime;
	float timer_time;


	void input();
	void update(float dt);
	void draw();
	void menu(sf::RenderWindow &window);

	bool testing;
	size_t clicks_made = 0;

	sf::Clock clock;

	float resx;
	float resy;

public:
	bool eventManager();
	Engine();
	~Engine() {}
	void start();
};

