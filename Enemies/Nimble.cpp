#include "Nimble.h"

Nimble::Nimble(const char *textureSheet, int x, int y, int spriteSizeXY, int numSprites) :
        GameObject(textureSheet, x, y, spriteSizeXY, numSprites) {
    this->xPos = x;
    this->yPos = y;
    this->fric = 0.95;
    this->tX = 0.0;
    this->tY = 0.0;
    this->life = 1;

}

Nimble::~Nimble() {

}

void Nimble::Move() {
    xPos += (int)tX;
    yPos += (int)tY;
    tX *= fric;
    tY *= fric;
    if (yPos>1000){
        alive = false;
    }
    GameObject::Translate(0, 1);
}

void Nimble::TakeHit() {
    this->life--;
    if(life==0){
        GameObject::Destroy();
    }
}
