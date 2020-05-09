#include "Clicker.h"
#include "Counter.h"
#include "Shop.h"

Clicker::Clicker(sf::RenderWindow &window) {

	coin_texture.loadFromFile("assets/coin.png");
	coin.setTexture(coin_texture);
	coin.setPosition(960 - 418 / 2, 540 - 484 / 2);

	coin_texture2.loadFromFile("assets/coin2.png");
	coin2.setTexture(coin_texture2);
	coin2.setPosition(960 - 370 / 2, 540 - 428 / 2);


	window.draw(coin);
	window.display();

}

void Clicker::isClicked(sf::RenderWindow &window) {
	timer = clock.getElapsedTime();
	sf::Event event;
	window.clear();
	Counter cnt(window, clicks_made);
	cnt.setCounter(clicks_made);
	window.draw(coin);
	Shop shop(window);
	window.display();
	while (window.pollEvent(event)) {

		if (timer.asSeconds() >= sf::seconds(1).asSeconds()) {
			clicks_per_sec = 0;
			clicks_per_sec = 1 + booster;
			clicks_made = clicks_made + clicks_per_sec;
			clicks_per_sec = 0;
			clock.restart();
		}

		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if ((sf::IntRect(960 - 418 / 2, 540 - 484 / 2, 418, 540).contains(sf::Mouse::getPosition(window))) && 
				event.mouseButton.button == sf::Mouse::Button::Left) {
					window.clear();
					window.draw(coin2);
					cnt.WhenClicked(window);
					window.display();
					++clicks_made;
					cnt.setCounter(clicks_made);
					std::cout << clicks_made << std::endl;
			}
			for (int i = 0; i < 4; i++) {
				if (sf::IntRect(0, i * 100, 160, 40).contains(sf::Mouse::getPosition(window))) {
					if (event.mouseButton.button == sf::Mouse::Button::Left) {
						booster = shop.BuyItem(clicks_made, booster);
						clicks_made = shop.minusBuyItem(clicks_made, booster);
					}
				}
			}
			break;
		default:
			break;
		}
	}
}



