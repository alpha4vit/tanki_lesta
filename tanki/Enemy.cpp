#include "Enemy.h"

Enemy::Enemy(Tank& tank, int& screenW, int&screenH, vector<Enemy>& enemies)
{
	
	this->img = Image();
	this->img.loadFromFile("image/tank.png");
	this->texture = Texture();
	this->texture.loadFromImage(this->img);
	this->sprite = Sprite();
	this->sprite.setTexture(this->texture);
	
	int x = 100 + rand() % (screenW - 200);
	int y = 100 + rand() % (screenH - 200);
	while ((x > tank.sprite.getPosition().x - 100 && x < tank.sprite.getPosition().x + 100) || (y > tank.sprite.getPosition().y - 100 && tank.sprite.getPosition().y+100 > y) && checkEnemies(enemies, x, y)) {
		x = 100 + rand() % (screenW - 200);
		y = 100 + rand() % (screenH - 200);
	}
	this->sprite.setPosition(x, y);
	this->sprite.setTextureRect(IntRect(164, 20, 77, 90));
	this->sprite.setOrigin(40, 45);
}

bool Enemy::checkEnemies(vector<Enemy>& enemies, const int& x, const int& y)
{
	for (Enemy enemy : enemies) {
		if (enemy.sprite.getPosition().x - 100 < x && enemy.sprite.getPosition().x + 100 < x || enemy.sprite.getPosition().y - 100 < y && enemy.sprite.getPosition().y + 100 < y) {
			return false;
		}
	}
	return true;
}
 