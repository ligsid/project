#include "Player.h"

Player::Player() {
	//��� ������ ��������
}

sf::Sprite Player::getSprite() {
	return this->Sprite;
}

void Player::update(float elapsedTime) {
	this->Sprite.setPosition(this->Position);
}