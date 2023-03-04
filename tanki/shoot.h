#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h"
#include"movement.h"
#include"loadIMG.h"
using namespace std;
using namespace sf;
void shoot(Sprite& bullet,const float& speedBullet, bool& isShoot);
