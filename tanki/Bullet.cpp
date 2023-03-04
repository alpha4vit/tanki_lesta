#include "Bullet.h"

Bullet::Bullet()
{
	this->img = Image();
	if (!this->img.loadFromFile("image/bullet.png")) {
		exit(-1);
	}
	this->texture = Texture();
	this->texture.loadFromImage(this->img);
	this->sprite = Sprite();
	this->sprite.setTexture(this->texture);
	this->isShoot = true;
}

