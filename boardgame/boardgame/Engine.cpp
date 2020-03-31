#include "Engine.h"

Engine::Engine() {
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	window.create(sf::VideoMode(resolution.x, resolution.y), "Game");
}

void Engine::start() {
	sf::Clock clock;
	sf::Event event;
	while (window.isOpen()) {
		float time = (float)clock.getElapsedTime().asMilliseconds();
		clock.restart();
		time = (float)(time * 2);

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		input();
		update(time);
		draw();
		
	}
}

void Engine::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}
	// добавить взаимодействие с кнопочкой
}

void Engine::update(float dt) {
	//player.update(dt);
}

void Engine::draw() {
	window.clear(sf::Color::Black);
	window.draw(BackgroundSprite);
	window.draw(player.getSprite());
	menu(window);
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
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(345, 0);
	sf::Event event;
	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf:: Color::White);
		menuNum = 0;
		window.clear(sf::Color::White);

		if (sf::IntRect(100, 30, 300, 50).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Black); menuNum = 1; }
		if (sf::IntRect(100, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Black); menuNum = 2; }
		if (sf::IntRect(100, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Black); menuNum = 3; }

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
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