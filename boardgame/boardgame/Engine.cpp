#include "Engine.h"
#include <iostream>
#include "Counter.h"

Engine::Engine(){
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	resx = resolution.x;
	resy = resolution.y;
	window.create(sf::VideoMode(1024, 768), "Clicker Game");
	window.setFramerateLimit(30);
}

void Engine::start() {
	while (window.isOpen()) {
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		input();
		draw();
	}
}

void Engine::ClickerInit(sf::RenderWindow &window) {

}

void Engine::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}
}

void Engine::update(float dt) {
	
}

void Engine::draw() {
	menu(window);
	window.display();
}

void Engine::menu(sf::RenderWindow &window) {
	sf::Event event;
	bool isMenu = true;
	int menuNum = 0;


	while (startmenu.MenuEvents(window)) {
		window.clear();

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		startmenu.draw(window);
	}
}
