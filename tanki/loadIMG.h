#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h"
#include"movement.h"
using namespace sf;
void loadBullet(Sprite& bullet, int screenWidth, int screenHeight);
void loadTank(Sprite& tank, int screenWidth, int screenHeight);