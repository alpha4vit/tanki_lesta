#include "Tank.h"

Tank::Tank(int& screenW, int& screenH)
{
	this->img = Image();
	if (!this->img.loadFromFile("image/tank.png")) {
		exit(-1);
	}
	this->texture = Texture();
	this->texture.loadFromImage(this->img);
	this->sprite = Sprite();
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(IntRect(129, 121, 146, 276));
	this->sprite.setPosition(Vector2f(screenW/2, screenH-180));
	this->sprite.setOrigin(Vector2f(70, 180));
}
