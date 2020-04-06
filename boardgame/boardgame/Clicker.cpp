#include "Clicker.h"
#include "Counter.h"

Clicker::Clicker(sf::RenderWindow &window) {

	coin_texture.loadFromFile("assets/coinframes.png");
	
	coin.setTexture(coin_texture);
	coin.setTextureRect(frames[0]);
	coin.setPosition(960 - 418 / 2, 540 - 484 / 2);

}

void Clicker::isClicked(sf::RenderWindow &window) {
	sf::Event event;
	Counter cnt(window, clicks_made);
	cnt.setCounter(clicks_made);

	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if (sf::IntRect(960 - 418 / 2, 540 - 484 / 2, 418, 540).contains(sf::Mouse::getPosition(window))) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					coin.setTextureRect(frames[1]);
					cnt.WhenClicked(window);
					window.draw(coin);
					window.display();
					++clicks_made;
					cnt.setCounter(clicks_made);
					std::cout << clicks_made << std::endl;
				}
				else{
					coin.setTextureRect(frames[0]);
				}
			}
			break;
		default:
			break;
		}
	}
}



