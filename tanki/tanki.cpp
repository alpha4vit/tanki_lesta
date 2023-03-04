#pragma once

#include<SFML/Graphics.hpp>
#include"movement.h"
#include"loadIMG.h"
#include"shoot.h"
#include"Bullet.h"
#include"Tank.h"
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

   
    // creating objects

    Tank tank = *new Tank();
    Bullet bullet = *new Bullet();



    bool isShoot = false;
    Clock clk;
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
        game.draw(bullet.sprite);
        game.draw(tank.sprite);
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            moveUp(tank.sprite, speedTank);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            moveDown(tank.sprite, speedTank, screenHeight);
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            moveRight(tank.sprite, speedTank, screenWidth);
        }
        else if (Keyboard::isKeyPressed(Keyboard::A)) {
            moveLeft(tank.sprite, speedTank);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !isShoot) {
            bullet.sprite.setPosition(tank.sprite.getPosition().x , tank.sprite.getPosition().y);
            bullet.sprite.setRotation(tank.sprite.getRotation());
            isShoot = true;
        }
        if (isShoot) {
            shoot(bullet.sprite, speedBullet, isShoot);
        }


        game.display();
    }

    return 0;
}

