#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"


class Engine
{
private:
	sf::Sprite BackgroundSprite;
	sf::Texture BackgroundTexture;
	sf::RenderWindow window;
	
	void input();
	void update(float dt);
	void draw();
	void menu(sf::RenderWindow &window);
	Player player;

public:
	Engine();
	~Engine() {}
	void start();
};

