#pragma once
#include<SFML/Graphics.hpp>

class StartMenu
{
public:
	StartMenu();

	void draw(sf::RenderWindow &window);
	bool MenuEvents(sf::RenderWindow &window);

	int WichGoingToPressed(sf::RenderWindow & window);

private:
	sf::Texture aboutTexture;
	sf::Sprite about;

	sf::Texture background;
	sf::Sprite menuBg;

	int selectedItemIndex;
	sf::Text menu[3];
	sf::Font font;
};

