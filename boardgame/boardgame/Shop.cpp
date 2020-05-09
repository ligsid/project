#include "Shop.h"

Shop::Shop(sf::RenderWindow &window){
	font.loadFromFile("font.ttf");
	
	text_string[0] = "boost x2";
	text_string[1] = "boost x3";
	text_string[2] = "boost x4";
	text_string[3] = "boost x5";

	for (int i = 0; i < 4; i++) {
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setString(text_string[i]);
		text[i].setPosition(0, i*100);
		window.draw(text[i]);
	}

}

int Shop::minusBuyItem(size_t clicks_made, int booster) {
	if (clicks_made == pr_boostx2) {
		clicks_made -= pr_boostx2;
		return clicks_made;
	}
	if (clicks_made == pr_boostx3) {
		clicks_made -= pr_boostx3;
		return clicks_made;
	}
	if (clicks_made == pr_boostx4) {
		clicks_made -= pr_boostx4;
		return clicks_made;
	}
	if (clicks_made == pr_boostx5) {
		clicks_made -= pr_boostx5;
		return clicks_made;
	}
	else {
		return clicks_made;
	}
}

int Shop::BuyItem(size_t clicks_made, int booster) {
	if (clicks_made == pr_boostx2) {
		clicks_made -= pr_boostx2;
		return booster * boostx2;
	}
	if (clicks_made == pr_boostx3) {
		clicks_made -= pr_boostx3;
		return booster * boostx3;
	}
	if (clicks_made == pr_boostx4) {
		clicks_made -= pr_boostx4;
		return booster * boostx4;
	}
	if (clicks_made == pr_boostx5) {
		clicks_made -= pr_boostx5;
		return booster * boostx5;
	}
	else {
		return clicks_made;
	}
}