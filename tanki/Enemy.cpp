#include "Enemy.h"

Enemy::Enemy(Tank& tank)
{
	srand(time(NULL));
	this->img = Image();
	this->img.loadFromFile("image/tank.png");
	this->texture = Texture();
	this->texture.loadFromImage(this->img);
	this->sprite = Sprite();
	this->sprite.setTexture(this->texture);
	int screenW = VideoMode::getDesktopMode().width;
	int screenH = VideoMode::getDesktopMode().height;
	int x = 100 + rand() % (screenW - 100);
	int y = 100 + rand() % (screenH - 100);
	while ((x > tank.sprite.getPosition().x - 200 && x < tank.sprite.getPosition().x + 200) || (y > tank.sprite.getPosition().y - 100 && tank.sprite.getPosition().y+100 > y)) {
		x = 100 + rand() % (screenW - 100);
		y = 100 + rand() % (screenH - 100);
	}
	this->sprite.setPosition(x, y);
	this->sprite.setTextureRect(IntRect(129, 121, 146, 276));
}
 