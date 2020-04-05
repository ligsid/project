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
}

void Engine::update(float dt) {
	//player.update(dt);
}

void Engine::draw() {
	menu(window);
}

void Engine::menu(sf::RenderWindow &window) {
	sf::Event event;
	bool isMenu = true;
	int menuNum = 0;


	while (isMenu) {
		window.clear();

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		isMenu = startmenu.MenuEvents(window);
		startmenu.draw(window);
	}
}
