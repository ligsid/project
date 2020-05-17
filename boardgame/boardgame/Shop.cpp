#include "Shop.h"

Shop::Shop(sf::RenderWindow &window){
	font.loadFromFile("font.ttf");
	
	text_string[0] = "Gold +2";
	text_string[1] = "Gold +3";
	text_string[2] = "Gold +4";
	text_string[3] = "Gold +5";

	for (int i = 0; i < 4; i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setString(text_string[i]);
		text[i].setPosition(940, i*100+340);
	}
}

void Shop::shop_draw(sf::RenderWindow &window) {
	for (int i = 0; i < 4; i++) {
		window.draw(text[i]);
	}
}
int Shop::BuyItem(size_t clicks_made, int booster, int numboost) {
	if (clicks_made >= pr_boost[numboost]) {
		return booster += boost[numboost];
	}
	else {
		return booster;
	}
}
int Shop::minusBuyItem(size_t clicks_made, int booster, int numboost) {
	if (clicks_made >= pr_boost[numboost]) {
		return clicks_made -= pr_boost[numboost];
	}
	else {
		return clicks_made;
	}
}

int Shop::WichGoingToPressed(sf::RenderWindow &window) {
	if (sf::IntRect(940, 340, 160, 40).contains(sf::Mouse::getPosition(window))) {
		text[0].setFillColor(sf::Color::Red);
		return 0;
	}
	if (sf::IntRect(940,440, 160, 40).contains(sf::Mouse::getPosition(window))) {
		text[1].setFillColor(sf::Color::Red);
		return 1;
	}
	if (sf::IntRect(940,540, 160, 40).contains(sf::Mouse::getPosition(window))) {
		text[2].setFillColor(sf::Color::Red);
		return 2;
	}
	if (sf::IntRect(940,640, 160, 40).contains(sf::Mouse::getPosition(window))) {
		text[3].setFillColor(sf::Color::Red);
		return 3;
	}
	else{
		text[0].setFillColor(sf::Color::White);
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::White);
	}
	return 4;
}
