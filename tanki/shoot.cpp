#include "shoot.h"

void shoot(const Sprite& tank, Sprite& bullet, float& speedBullet, bool&isShoot)
{   
    int direction = 0;
    int min = 361;
    for (int i = 0; i < 361; i += 90) {
        if (abs((int)bullet.getRotation() - i) < min) {
            direction = i;
            min = (int)bullet.getRotation() - i;
        }
    }

    switch (direction)
    {
    case 0: bullet.move(0, -speedBullet);
    case 90: bullet.move(speedBullet, 0);
    case 180: bullet.move(0, speedBullet);
    case 270: bullet.move(-speedBullet, 0);
    default:
        break;
    }
    if (!(bullet.getPosition().x > 0 && bullet.getPosition().x < 1920 && bullet.getPosition().y > 0 && bullet.getPosition().y < 1080)) {
        isShoot = false;
        bullet.setPosition(-50, -50);
    }
}


