#pragma once

#include<SFML/Graphics.hpp>
#include<vector>
#include"movement.h"
#include"loadIMG.h"
#include"shoot.h"
#include"Bullet.h"
#include"Tank.h"
#include"Background.h"
#include"Enemy.h"
#include<thread>
#include<chrono>
#include<ctime>

using namespace std;
using namespace sf;

void drawingBullets(RenderWindow& game, vector<Bullet>& bullets, float& speedBullet);

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    // ------------------ creating game window and background


    int screenWidth = VideoMode::getDesktopMode().width;
    int screenHeight = VideoMode::getDesktopMode().height;
    if (screenWidth > 1920) { screenWidth = 1920; }
    if (screenHeight > 1080) { screenHeight = 1080; }
    RenderWindow game(VideoMode(screenWidth, screenHeight), "Tanki");
    Background bg = *new Background();
    //game.setFramerateLimit(144);
    
   
    // ------------   creating objects

    
    Tank tank = *new Tank(screenWidth, screenHeight);
    vector<Bullet> bullets;
    vector<Enemy> enemies;
    for (int i = 0; i < 3; ++i) {
        enemies.push_back(*new Enemy(tank, screenWidth, screenHeight, enemies));
    }

    bool isShoot = false;
    Clock clk;


    while (game.isOpen()) {
        Event ev; 
        while (game.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                game.close();
            }
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Space)
                {
                    Bullet bullet = *new Bullet();
                    bullet.sprite.setPosition(tank.sprite.getPosition().x, tank.sprite.getPosition().y);
                    bullet.sprite.setRotation(tank.sprite.getRotation());
                    bullets.push_back(bullet);
                }
            }
        }

        float elapsed = clk.restart().asMilliseconds();
        float speedTank = 300 * elapsed / 1000;
        float speedBullet = 1100 * elapsed / 1000;


        game.clear();
        game.draw(bg.sprite);
        for (int i = 0; i < size(bullets); ++i) {
            if (bullets[i].getState() == false) {
                bullets.erase(bullets.begin() + i);
                --i;
            }
            else {
                game.draw(bullets[i].sprite);
            }
        }
        thread shooting(drawingBullets, ref(game), ref(bullets), ref(speedBullet));
        game.draw(tank.sprite);
        for (Enemy enemy : enemies) {
            game.draw(enemy.sprite);
        }
        rotateEnemy(enemies);
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
       
        shooting.join();
        game.display();
    }

    return 0;
}

void drawingBullets(RenderWindow& game, vector<Bullet>& bullets, float& speedBullet) {
    for (int i = 0; i < bullets.size(); ++i) {
        if (bullets[i].getState()) {
            shoot(bullets[i], speedBullet);
        }
        else {
            bullets.erase(bullets.begin() + i);
            --i;
        }
    }
}


