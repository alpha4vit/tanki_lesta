#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h"
#include"movement.h"
#include"loadIMG.h"
#include"shoot.h"
using namespace std;
using namespace sf;
int main()
{
    setlocale(LC_ALL, "rus");

    // creating game window


    int screenWidth = VideoMode::getDesktopMode().width;
    int screenHeight = VideoMode::getDesktopMode().height;
    RenderWindow game(VideoMode(screenWidth, screenHeight), "Tanki");
    game.setFramerateLimit(144);
    

    //load images and create objects

    Image imageTank;
    if (!imageTank.loadFromFile("image/tank.png")) {
        cout << "Не удалось загрузить текстуру танка, проверьте ее наличие по заданному пути в проекте: image/tank.png";
        exit(-1);
    }
    Texture textureTank;
    textureTank.loadFromImage(imageTank);
    Sprite tank;
    tank.setTexture(textureTank);
    tank.setTextureRect(IntRect(129, 121, 146, 276));
    Clock clk;
    tank.setPosition(Vector2f(screenWidth / 2, screenHeight - 280));
    tank.setOrigin(Vector2f(70, 180));


    Image imgBullet;
    if (!imgBullet.loadFromFile("image/bullet.png")) {
        cout << "Не удалось загрузить текстуру снаряда, проверьте ее наличие по заданному пути в проекте: bullet/tank.png";
        exit(-1);
    }
    Texture bulletTexture;
    bulletTexture.loadFromImage(imgBullet);
    Sprite bullet;
    bullet.setTexture(bulletTexture);
    bullet.setPosition(-50, -50);
    


    bool isShoot = false;

    while (game.isOpen()) {
        Event ev;
        while (game.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                game.close();
            }
        }

        float elapsed = clk.restart().asMilliseconds();
        float speedTank = 300 * elapsed / 1000;
        float speedBullet = 1000 * elapsed / 1000;


        game.clear();
        game.draw(bullet);
        game.draw(tank);
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            moveUp(tank, speedTank);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            moveDown(tank, speedTank, screenHeight);
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            moveRight(tank, speedTank, screenWidth);
        }
        else if (Keyboard::isKeyPressed(Keyboard::A)) {
            moveLeft(tank, speedTank);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !isShoot) {
            bullet.setPosition(tank.getPosition().x , tank.getPosition().y);
            bullet.setRotation(tank.getRotation());
            isShoot = true;
        }
        if (isShoot) {
            shoot(bullet, speedBullet, isShoot);
        }


        game.display();
    }

    


    return 0;
}

