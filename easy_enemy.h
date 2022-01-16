#ifndef ENEMY_H
#define ENEMY_H

#include "all_incl.h"

enum ENEMY_ANIMATION {
    IDLE = 0,
    SHOOTING,
    DYING
};

class Enemy {
    private:
        sf::Sprite enemy_sprite;
        sf::Texture enemy_texture;
        short animations_number;
        sf::Vector2f enemy_position;
    public:
        Enemy();
        ~Enemy();
        void initAnimations();
        void updateAnimations();
        void renderEnemy();
        void destroyEnemy();
};

#endif
