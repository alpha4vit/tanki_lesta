#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h"
#include"movement.h"
#include"loadIMG.h"
using namespace std;
using namespace sf;
void shoot(const Sprite& tank, Sprite& bullet, float& speedBullet, bool& isShoot);
