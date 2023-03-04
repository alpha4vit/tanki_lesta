#include "shoot.h"

void shoot(Bullet& bullet,const float& speedBullet)
{   
    switch ((int)bullet.sprite.getRotation())
    {
    case 0: {bullet.sprite.move(0, -speedBullet); break; }
    case 90: {bullet.sprite.move(speedBullet, 0); break; }
    case 180: {bullet.sprite.move(0, speedBullet); break; }
    case 270: {bullet.sprite.move(-speedBullet, 0); break; }
    default:
        break;
    }
    if (!(bullet.sprite.getPosition().x > 0 && bullet.sprite.getPosition().x < 1920 && bullet.sprite.getPosition().y > 0 && bullet.sprite.getPosition().y < 1080)) {
        bullet.setState(false);
        bullet.sprite.setPosition(-50, -50);
    }
}


