#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"



class Engine
{
protected:
	sf::RenderWindow window;
private:
	void input();
	void update(float dt);
	void draw();
	void menu(sf::RenderWindow &window);
	void play(sf::RenderWindow &window);
	Player player;

public:
	Engine();
	~Engine() {}
	void start();
};

