#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h";
using namespace std;
using namespace sf;

void moveUp(Sprite tank, float elapsed);
void moveDown(Sprite tank, float elapsed);
void moveRight(Sprite tank, float elapsed);
void moveLeft(Sprite tank, float elapsed);
