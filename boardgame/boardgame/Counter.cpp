#include "Counter.h"
#include <string>

Counter::Counter(sf::RenderWindow &window, size_t counter) {
	cnt = counter;
	font.loadFromFile("font.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Yellow);
	text.setString(std::to_string(cnt));
	text.setPosition(512 + 250, 384 + 250);
	window.draw(text);
}

void Counter::WhenClicked(sf::RenderWindow &window) {
	text.setString(std::to_string(cnt));
	//drawCnt(window);
}

void Counter::drawCnt(sf::RenderWindow &window) {
	window.draw(text);
}

void Counter::setCounter(size_t counter) {
	cnt = counter;
}