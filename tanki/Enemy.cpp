#include "Enemy.h"

Enemy::Enemy()
{
	this->img = Image();
	this->img.loadFromFile("image/tank.png");
	this->texture = Texture();
	this->texture.loadFromImage(this->img);
	this->sprite = Sprite();
	this->sprite.setTexture(this->texture);
}
