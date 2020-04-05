#include "Clicker.h"

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
	sf::Event event;

	window.clear();
	window.draw(coin);
	window.display();

	bool isclick = false;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left){
				if (sf::IntRect(960 - 418 / 2, 540 - 484 / 2, 418, 540).contains(sf::Mouse::getPosition(window))) {
					window.clear();
					window.draw(coin2);
					window.display();
					isclick = true;
					++clicks_made;
					std::cout << clicks_made << std::endl;
				}
				break;
		default:
			break;
			}
		}
	}
}



