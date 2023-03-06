#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include"object.h"
using namespace sf;
using namespace std;
class Tank : public object
{
public:
	Tank(int& screenW, int& screenH);
};

