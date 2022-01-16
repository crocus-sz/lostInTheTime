// main hero's header file
#ifndef HERO_H
#define HERO_H

#include "all_incl.h"
enum HERO_ANIMATION {
    IDLE = 0,
    MOVING_LEFT,
    MOVING_RIGHT,
    JUMPING,
    SITTING
};

class Hero {

    private:
        sf::Sprite main_hero_sprite;
        sf::Texture main_hero_texture;
        sf::IntRect currentFrame;
        sf::Clock heroAnimationTimer;
        short animations_number;
        sf::Vector2f hero_position;

    public:
        Hero();
        ~Hero();

        //graphics
        void update();
        void render(sf::RenderWindow &win);
        void setHeroSprite();

        //movement
        void keyboardMovement();
        void  updateHeroPosition();
        float getHeroPositionX();
        float getHeroPositionY();

        //animations
        void initAnimations();
        void updateAnimations();

        //physics
        float acceleration;
        float drag;
        float maxVelocity;
        float minVelocity;
        float gravity;
        float maxGravitySpeed;
        sf::Vector2f velocity;
        void initPhysics();
        void updatePhysics();
        void moving(const float dir_x, const float dir_y);

        //view
        void initView();
};


#endif
