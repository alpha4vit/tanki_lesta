#include "shoot.h"

void shoot(Sprite& bullet,const float& speedBullet, bool&isShoot)
{   
    switch ((int)bullet.getRotation())
    {
    case 0: {bullet.move(0, -speedBullet); break; }
    case 90: {bullet.move(speedBullet, 0); break; }
    case 180: {bullet.move(0, speedBullet); break; }
    case 270: {bullet.move(-speedBullet, 0); break; }
    default:
        break;
    }
    if (!(bullet.getPosition().x > 0 && bullet.getPosition().x < 1920 && bullet.getPosition().y > 0 && bullet.getPosition().y < 1080)) {
        isShoot = false;
        bullet.setPosition(-50, -50);
    }
}


