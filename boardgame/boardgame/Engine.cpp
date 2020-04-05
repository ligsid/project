#include "Engine.h"
#include<iostream>


Engine::Engine(){
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	resx = resolution.x;
	resy = resolution.y;
	window.create(sf::VideoMode(resolution.x, resolution.y), "Clicker Game");
}

void Engine::start() {
	while (window.isOpen()) {
		float time = (float)clock.getElapsedTime().asMilliseconds();
		clock.restart();
		time = (float)(time * 2);
		menu(window);
		input();
		update(time);
		draw();
		
	}
}

void Engine::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}
}

void Engine::update(float dt) {
	//player.update(dt);
}

void Engine::draw() {
	window.clear(sf::Color::Black);
	window.display();
}

void Engine::menu(sf::RenderWindow &window) {
	sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("assets/start.png");
	menuTexture2.loadFromFile("assets/options.png");
	menuTexture3.loadFromFile("assets/exit.png");
	aboutTexture.loadFromFile("assets/about.jpg");
	menuBackground.loadFromFile("assets/BackGround.jpg");
	sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(960, 450);
	menu2.setPosition(960, 550);
	menu3.setPosition(960, 650);
	menuBg.setPosition(0, 0);
	sf::Event event;

	sf::Texture coin_texture;
	sf::Texture coin_texture2;
	coin_texture.loadFromFile("assets/coin.png");
	coin_texture2.loadFromFile("assets/coin2.png");
	sf::Sprite coin(coin_texture);
	sf::Sprite coin2(coin_texture2);
	coin.setPosition(960 - 418/2, 540 - 484/2);
	coin2.setPosition(960 - 370 / 2, 540 - 428 / 2);
	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf:: Color::White);
		menuNum = 0;
		window.clear();

		if (sf::IntRect(960, 450, 160, 39).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Black); menuNum = 1; }
		if (sf::IntRect(960, 550, 160, 39).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Black); menuNum = 2; }
		if (sf::IntRect(960, 650, 160, 39).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Black); menuNum = 3; }

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) {
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.clear();
					window.draw(coin);
					window.display();
					if (sf::IntRect(960 - 418 / 2, 540 - 484 / 2, 418, 540).contains(sf::Mouse::getPosition(window))) {
						if (eventManager()) {
							window.clear();
							window.draw(coin2);
							window.display();
						}
					}
				}
				
			}
			if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}

bool Engine::eventManager() {
	bool flag = false;
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left) {
				flag = true;
				++clicks_made;
				std::cout << clicks_made << std::endl;
				break;
		default:
			break;
			}
		}
	}
	return flag;
}
