#pragma once

#include "Engine.h"
#include <string>


class Engine;
class Button:Engine
{
private:
	sf::Texture buttontexture;
	sf::Sprite buttonsprite(sf::Texture &texture);
	std::string mc;
	int mx;
	int my;
public:
	Button(int coordx, int coordy, std::string c);
	~Button(){}
	int isMouseOnButton(int height, int width);
	void isPressed();
	void ButtonDraw();
};

