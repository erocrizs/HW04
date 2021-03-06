#include "BasicEnemyBullet.h"
#include "SpellCardShoot.h"
#include "Enemy.h"
#include "BulletStage.h"

SpellCardShoot* SpellCardShoot::getInstance(float dt, Enemy* e) {
    static SpellCardShoot shoot(dt, e);
    return &shoot;
}

void SpellCardShoot::operator() (BulletStage* stage, vec2f position) {
    float maxHP = e->getTotalHP();
    float remHP = e->getRemainingHP();
    float percentage = remHP/maxHP;
    vec2f spawnPos = position;
    float baseSpeed = 160;

    if(percentage <= 1.00) {
        float jumpRate = (360/3.0);
        bulletDeg[0] += dt*(jumpRate-18);
        if(bulletDeg[0]>360) bulletDeg[0] -= 360;

        sf::Color color(102, 194, 255);
        float speed = baseSpeed;
        vec2f direction(0, -1);
        for(int i=0; i<7; i++) {
            float deg = bulletDeg[0] - (i*dt*jumpRate);
            if(deg<0) deg += 360;
            vec2f thisDir = rotate(direction, deg);
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(8, 8), speed, color));
        }
    }
    if(percentage <= 0.90) {
        float jumpRate = (360/3.0);
        bulletDeg[1] -= dt*(jumpRate-6);
        if(bulletDeg[1]<0) bulletDeg[1] += 360;

        sf::Color color(255, 179, 255);
        float speed = baseSpeed*0.60f;
        vec2f direction(0, -1);
        for(int i=0; i<5; i++) {
            float deg = bulletDeg[1] + (i*dt*jumpRate*0.5);
            if(deg > 360) deg -= 360;
            vec2f thisDir = rotate(direction, deg);
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(12, 12), speed, color));
        }
    }
    if(percentage <= 0.70) {
        float jumpRate = (360/2);
        bulletDeg[2] += dt*(jumpRate-30);
        if(bulletDeg[2]>360) bulletDeg[2] -= 360;

        sf::Color color(255, 0, 0, 180);
        float speed = baseSpeed*0.50f;
        vec2f direction(0, -1);
        for(int i=0; i<2; i++) {
            float deg = bulletDeg[2] - (i*dt*jumpRate);
            if(deg < 0) deg += 360;
            vec2f thisDir = rotate(direction, deg);
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(80, 80), speed, color));
        }
    }
    if(percentage <= 0.50) {
        float jumpRate = (360/7.0);
        bulletDeg[3] += dt*(jumpRate);
        if(bulletDeg[3]>360) bulletDeg[3] -= 360;

        sf::Color color(0, 0, 255);
        float speed = baseSpeed*0.8;
        float otherSpeed = speed*1.2;
        vec2f direction(0, -1);
        for(int i=0; i<5; i++) {
            float deg = bulletDeg[3] - (i*dt*jumpRate);
            if(deg<0) deg += 360;
            vec2f thisDir = rotate(direction, deg);
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(12, 12), speed, color));
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(12, 12), otherSpeed, color));
        }
    }

    if(percentage <= 0.40) {
        float jumpRate = (360/7.0);
        bulletDeg[4] -= dt*(jumpRate-6);
        if(bulletDeg[4]<0) bulletDeg[4] += 360;

        sf::Color color(255, 255, 153);
        float speed = baseSpeed*1.10f;
        vec2f direction(0, -1);
        for(int i=0; i<5; i++) {
            float deg = bulletDeg[4] + (i*dt*jumpRate*3);
            if(deg > 360) deg -= 360;
            vec2f thisDir = rotate(direction, deg);
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(25, 25), speed, color));
        }
    }
    if(percentage <= 0.20) {
        float jumpRate = (360/2.0);
        bulletDeg[5] += dt*(jumpRate+12);
        if(bulletDeg[5]<0) bulletDeg[5] -= 360;

        sf::Color color(153, 153, 255);
        float speed = baseSpeed*1.20f;
        float otherSpeed = speed*1.2;
        vec2f direction(0, -1);
        for(int i=0; i<5; i++) {
            float deg = bulletDeg[5] - (i*dt*jumpRate);
            if(deg > 360) deg += 360;
            vec2f thisDir = rotate(direction, deg);
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(25, 25), speed, color));
            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(25, 25), otherSpeed, color));
        }
    }
    if(percentage <= 0.10) {
        float jumpRate = (360/8.0);
        bulletDeg[6] += dt*(jumpRate+6);
        if(bulletDeg[6]<0) bulletDeg[6] -= 360;

        sf::Color color(255, 255, 255);
        float speed = baseSpeed*1.8;
        vec2f direction(0, 1);
        for(int i=0; i<8; i++) {
            float deg = bulletDeg[6] - (i*jumpRate);
            if(deg > 360) deg += 360;
            vec2f thisDir = rotate(direction, deg);
            if(thisDir.y<0) thisDir = vec2f(thisDir.x, -thisDir.y);

            stage->addEnemyBullet(new BasicEnemyBullet(stage, position, thisDir,  vec2f(12, 12), speed, color));
        }
    }
}
