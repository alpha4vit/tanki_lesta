#pragma once
#include<SFML/Graphics.hpp>
#include"object.h"
#include"Tank.h"

using namespace sf;
using namespace std;
class Enemy : public object
{
public:
	Enemy(Tank& tank, int& screenW, int& screenH, vector<Enemy>& enemies);
private:
	bool checkEnemies(vector<Enemy>& enemies, const int& x, const int& y);
};

