#include "StartMenu.h"
#include "Clicker.h"
#include "Counter.h"
#include "Shop.h"

StartMenu::StartMenu() {
	aboutTexture.loadFromFile("assets/shop.jpg");
	about.setTexture(aboutTexture);

	background.loadFromFile("assets/startmenu.jpg");
	menuBg.setTexture(background);

	font.loadFromFile("font.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Start");
	menu[0].setPosition(470, 250);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Shop");
	menu[1].setPosition(470, 320);


	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(470, 390);

}

void StartMenu::draw(sf::RenderWindow &window) {

	window.draw(menuBg);
	for (int i = 0; i < 3; i++) {
		window.draw(menu[i]);
	}
	window.display();
}



bool StartMenu::MenuEvents(sf::RenderWindow &window) {
	bool isMenu = true;
	Clicker clicker(window, save[0], save[1]);
	int menuNum = WichGoingToPressed(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (menuNum == 1) {
			sf::Event event3;
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.pollEvent(event3);
				if (event3.type == sf::Event::Closed) {
					window.close();
				}
				clicker.setCM(save[0]);
				clicker.setbooster(save[1]);
				window.clear();
				clicker.isClicked(window);
			}
			save[0] = clicker.getCM();
			save[1] = clicker.getbooster();
		}
		if (menuNum == 2) {
			window.clear();
			Shop shop(window);
			sf::Event event2;
			int numboost = 0;
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.draw(about);
				window.pollEvent(event2);
				if (event2.type == sf::Event::Closed) {
					window.close();
				}
				numboost = shop.WichGoingToPressed(window);
				if (event2.mouseButton.button == sf::Mouse::Button::Left) {
					save[1] = shop.BuyItem(save[0], save[1], numboost);
					save[0] = shop.minusBuyItem(save[0], save[1], numboost);
				}
				shop.shop_draw(window);
				window.display();
			}
		}
		if (menuNum == 3) {
			window.close();
			return false;
		}
	}
	return isMenu;
}


int StartMenu::WichGoingToPressed(sf::RenderWindow &window) {
	if (sf::IntRect(470, 250, 100, 25).contains(sf::Mouse::getPosition(window))) {
		menu[0].setFillColor(sf::Color::Red);
		return 1;
	}
	if (sf::IntRect(470, 320, 100, 25).contains(sf::Mouse::getPosition(window))) {
		menu[1].setFillColor(sf::Color::Red);
		return 2;
	}
	if (sf::IntRect(470, 390, 100, 25).contains(sf::Mouse::getPosition(window))) {
		menu[2].setFillColor(sf::Color::Red);
		return 3;
	}
	else {
		menu[0].setFillColor(sf::Color::White);
		menu[1].setFillColor(sf::Color::White);
		menu[2].setFillColor(sf::Color::White);
	}
}