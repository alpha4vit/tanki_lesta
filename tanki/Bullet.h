#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Bullet
{
private:
	Image img;
	Texture texture;
	bool isShoot;
public:
	Sprite sprite;
	Bullet();

	void setState(bool isShoot) {
		this->isShoot = isShoot;
	}

	bool getState() {
		return this->isShoot;
	}
};

