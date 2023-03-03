#pragma once
#include "loadIMG.h"

void loadBullet(Sprite& bullet, int screenWidth, int screenHeight)
{
    Image imgBullet;
    if (!imgBullet.loadFromFile("image/bullet.png")) { 
        cout << "�� ������� ��������� �������� �������, ��������� �� ������� �� ��������� ���� � �������: bullet/tank.png"; 
        exit(-1);
    }
    Texture bulletTexture;
    bulletTexture.loadFromImage(imgBullet);
    bullet.setTexture(bulletTexture);
    bullet.setPosition(-50, -50);

}

void loadTank(Sprite& tank, int screenWidth, int screenHeight)
{
    
    Image imageTank;
    if (!imageTank.loadFromFile("image/tank.png")) {
        cout << "�� ������� ��������� �������� �����, ��������� �� ������� �� ��������� ���� � �������: image/tank.png";
        exit(-1);
    }
    Texture textureTank;
    textureTank.loadFromImage(imageTank);
    tank.setTexture(textureTank);
    tank.setTextureRect(IntRect(129, 121, 146, 276));
    Clock clk;
    tank.setPosition(Vector2f(screenWidth / 2, screenHeight - 280));
    tank.setOrigin(Vector2f(70, 180));
    
}
