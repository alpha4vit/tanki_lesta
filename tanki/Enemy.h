#pragma once
#include<SFML/Graphics.hpp>
#include"object.h"
#include"Tank.h"
#include<ctime>
using namespace sf;
using namespace std;
class Enemy : public object
{
public:
	Enemy(Tank& tank);
};

