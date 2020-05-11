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

int Shop::minusBuyItem(size_t clicks_made, int booster, int numboost) {
	if (numboost == boostx2 - 1 && clicks_made >= pr_boostx2) {
		clicks_made = clicks_made - pr_boostx2;
	}
	if (numboost == boostx3 - 1 && clicks_made >= pr_boostx3) {
		clicks_made = clicks_made - pr_boostx3;
	}
	if (numboost == boostx4 - 1 && clicks_made >= pr_boostx4) {
		clicks_made = clicks_made - pr_boostx4;
	}
	if (numboost == boostx5 - 1 && clicks_made >= pr_boostx5) {
		clicks_made = clicks_made - pr_boostx5;
	}
	return clicks_made;
}

int Shop::BuyItem(size_t clicks_made, int booster, int numboost) {
	if (numboost == boostx2 - 2 && clicks_made >= pr_boostx2) {
		return (boostx2 - 1);
	}
	if (numboost == boostx3 - 2 && clicks_made >= pr_boostx3) {
		return (boostx3 - 1);
	}
	if (numboost == boostx4 - 2 && clicks_made >= pr_boostx4) {
		return (boostx4 - 1);
	}
	if (numboost == boostx5 - 2 && clicks_made >= pr_boostx5) {
		return (boostx5 - 1);
	}
	else {
		return 0;
	}
}