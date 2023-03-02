#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h";
using namespace std;
using namespace sf;
Tank::Tank()
{
	this->posit = Vector2f(400, 600);
}

Vector2f Tank::getPosition()
{
	return this->posit;
}

void Tank::setPosition(int x, int y)
{
	this->posit = Vector2f(x, y);
}
