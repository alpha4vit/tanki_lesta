#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h";
using namespace std;
using namespace sf;

void moveUp(Sprite& tank, float& speedTank);
void moveDown(Sprite& tank, float& speedTank, int screenHeight);
void moveRight(Sprite& tank, float& speedTank, int screenWidth);
void moveLeft(Sprite& tank, float& speedTank);
