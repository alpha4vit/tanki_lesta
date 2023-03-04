#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Tank
{
private:
	Image img;
	Texture texture;

public:
	Sprite sprite;
	Tank();
};

