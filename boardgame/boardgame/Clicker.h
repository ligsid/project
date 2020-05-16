#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include<iostream>
#include "Engine.h"

class Clicker
{
public:
	Clicker() {}
	Clicker(sf::RenderWindow &window, size_t cm, size_t boost);
	void isClicked(sf::RenderWindow &window);
	void setCPS(size_t clicks_per_sec) {
		clicks_per_sec = this->clicks_per_sec;
	}
	void setCM(size_t clicks_made) {
		clicks_made = this->clicks_made;
	}
	void setbooster(int booster) {
		booster = this->booster;
	}
	size_t getCPS() {
		return clicks_per_sec;
	}
	size_t getCM() {
		return clicks_made;
	}
	int getbooster() {
		return booster;
	}
private:
	sf::Sprite coin;
	sf::Sprite coin2;
	sf::Texture coin_texture2;
	sf::Texture coin_texture;
	sf::Clock clock;
	sf::Time timer;
protected:
	size_t clicks_made = 0;
	size_t clicks_per_sec = 0;
	int booster = 1;
};

