#include "Button.h"

int Button::isMouseOnButton(int height, int width){
	if (sf::IntRect(mx, my, height, width).contains(sf::Mouse::getPosition(window))) {
		this->buttonsprite(buttontexture).setColor(sf::Color::Black);
	}
	return 0;
}
void Button::isPressed() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		
	}
}

Button::Button(int coordx, int coordy, std::string c) {
	mx = coordx;
	my = coordy;
	mc = c;
	this->buttontexture.loadFromFile(c);
	this->buttonsprite(buttontexture).setPosition(coordx, coordy);
}

void Button::ButtonDraw() {
	window.draw(buttonsprite(buttontexture));
	window.display();
}

sf::Sprite Button::buttonsprite(sf::Texture &texture) {
	sf::Sprite buttonsprite(buttontexture);
	return buttonsprite;
}