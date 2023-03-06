#pragma once

#include"object.h"
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Bullet : public object
{
public:
	Bullet();

	void setState(bool isShoot) {
		this->isShoot = isShoot;
	}

	bool getState() {
		return this->isShoot;
	}
};

