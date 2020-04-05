#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include "StartMenu.h"


class Engine
{
private:
	sf::Clock timer;
	sf::Time updateTime;
	float timer_time;


	void input();
	void update(float dt);
	void draw();

	bool testing;
	size_t clicks_made = 0;

	sf::Clock clock;
	StartMenu startmenu;
	sf::Event event;
	float resx;
	float resy;
protected:
	sf::RenderWindow window;
public:
	void menu(sf::RenderWindow &window);
	Engine();
	~Engine() {}
	void start();
};

