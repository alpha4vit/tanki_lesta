#pragma once
#include"movement.h"


void moveUp(Sprite tank, float elapsed)
{
	tank.setRotation(0);
	tank.move(0, -300 * elapsed / 1000);
}

void moveDown(Sprite tank, float elapsed)
{
	tank.setRotation(180);
	tank.move(0, 300 * elapsed / 1000);
}

void moveRight(Sprite tank, float elapsed)
{
	tank.setRotation(90);
	tank.move(300 * elapsed / 1000, 0);
}

void moveLeft(Sprite tank, float elapsed)
{
	tank.setRotation(270);
	tank.move(-300 * elapsed / 1000, 0);
}
