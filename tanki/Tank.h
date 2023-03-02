#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h";
using namespace std;
using namespace sf;
class Tank {

	Vector2f posit;

public:
	Tank();
	Vector2f getPosition();
	void setPosition(int x, int y);

};