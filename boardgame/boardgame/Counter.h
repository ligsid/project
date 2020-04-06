#pragma once

#include <SFML/Graphics.hpp>

class Counter
{
public:
	Counter(sf::RenderWindow &window, size_t counter);
	void WhenClicked(sf::RenderWindow &window);
	void drawCnt(sf::RenderWindow &window);
	void setCounter(size_t counter);
private:
	size_t cnt = 0;
	sf::Font font;
	sf::Text text;
	char cnt_text;
};

