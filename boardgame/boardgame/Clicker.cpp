#include "Clicker.h"
#include "Counter.h"
#include "Shop.h"
Clicker::Clicker(sf::RenderWindow &window, size_t cm, size_t boost) {
	clicks_made = cm;
	booster = boost;

	/*coin_texture.loadFromFile("assets/coin.png");
	coin.setTexture(coin_texture);
	coin.setPosition(960 - 418 / 2, 540 - 484 / 2);

	coin_texture2.loadFromFile("assets/coin2.png");
	coin2.setTexture(coin_texture2);
	coin2.setPosition(960 - 370 / 2, 540 - 428 / 2);*/

	coin_texture.loadFromFile("assets/coinframes.png");
	coin.setTexture(coin_texture);
	coin.setTextureRect(sf::IntRect(0, 0, 418, 484));
	coin.setPosition(960 - 418 / 2, 540 - 484 / 2);


}
void Clicker::isClicked(sf::RenderWindow &window) {
	timer = clock.getElapsedTime();
	sf::Event event;

	Counter cnt(window, clicks_made);

	cnt.setCounter(clicks_made);

	coin.setTextureRect(sf::IntRect(0, 0, 418, 484));
	coin.setPosition(960 - 418 / 2, 540 - 484 / 2);

	window.draw(coin);
	window.display();

	if (timer.asSeconds() >= sf::seconds(1).asSeconds()) {
		clicks_per_sec += booster;
		clicks_made += clicks_per_sec;
		clock.restart();
		cnt.WhenClicked(window);
		clicks_per_sec = 0;
	}

	while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					if (sf::IntRect(960 - 418 / 2, 540 - 484 / 2, 418, 540).contains(sf::Mouse::getPosition(window))) {
						coin.setTextureRect(sf::IntRect(418, 0, 370, 428));
						coin.setPosition(960 - 370 / 2, 540 - 428 / 2);
						cnt.WhenClicked(window);
						++clicks_made;
						cnt.setCounter(clicks_made);
						std::cout << clicks_made << std::endl;
						window.clear();
						window.draw(coin);
						window.display();
					}
				}
				break;
			default:
				break;
			}
	}
}
