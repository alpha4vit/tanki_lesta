#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include"Tank.h"
#include"movement.h"
using namespace std;
using namespace sf;
int main()
{

    int screenWidth = VideoMode::getDesktopMode().width;
    int screenHeight = VideoMode::getDesktopMode().height;
    setlocale(LC_ALL, "rus");
    RenderWindow game(VideoMode(screenWidth, screenHeight), "Tanki");
    game.setFramerateLimit(144);
    Image imageTank;
    if(!imageTank.loadFromFile("image/tank.png")){
        cout << "Не удалось загрузить текстуру танка, проверьте ее наличие по заданному пути в проекте: image/tank.png";
        return -1;
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
    if (!imgBullet.loadFromFile("image/bullet.png")) { cout << "Не удалось загрузить текстуру снаряда, проверьте ее наличие по заданному пути в проекте: bullet/tank.png";  return -1; }
    Texture bulletTexture;
    bulletTexture.loadFromImage(imgBullet);
    Sprite bullet;
    bullet.setTexture(bulletTexture);

    while (game.isOpen()) {
        Event ev;
        while (game.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                game.close();
            }
        }

        float elapsed = clk.restart().asMilliseconds();
        game.clear();
        game.draw(tank);
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            tank.setRotation(0);
            if (tank.getPosition().y - 180 > 0) {
                tank.move(0, -300 * elapsed / 1000);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            tank.setRotation(180);
            if (tank.getPosition().y + 260 < screenHeight) {
                tank.move(0, 300 * elapsed / 1000);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            tank.setRotation(90);
            if (tank.getPosition().x + 186 < screenWidth) {
                tank.move(300 * elapsed / 1000, 0);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::A)) {
            tank.setRotation(270);
            if (tank.getPosition().x - 178 > 0) {
                tank.move(-300 * elapsed / 1000, 0);
            }
        }
        game.display();
    }

    


    return 0;
}

