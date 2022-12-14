#pragma once

#include "SDL.h"

class GameObject {

public:
    GameObject(const char *textureSheet, int x, int y, int sheetSizeXY, int numSprites);
    ~GameObject();

    virtual void Render();
    bool isAlive();
    void Destroy();
    virtual void Move() = 0;
    void Translate(int x, int y);
    int xPos, yPos;
    float fric, tX, tY;
    bool alive = true;
    SDL_Texture *objTexture;
    SDL_Rect srcR, destR;
    SDL_Rect gSpriteClips[3];
    static int frame;
    static int curSprite;

    void Update();
};