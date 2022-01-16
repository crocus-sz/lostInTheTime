#include "main_hero.h"
#include "game.h"
#include <iostream>


Hero::Hero() {
    this->setHeroSprite();
    this->initAnimations();
    this->initPhysics();

    this->animations_number = IDLE;
}

Hero::~Hero() {
}

void Hero::render(sf::RenderWindow &win) {
    win.draw(this->main_hero_sprite);
}
void Hero::update() {
    this->keyboardMovement();
    this->updateAnimations();
    this->updatePhysics();
    this->updateHeroPosition();
}

void Hero::setHeroSprite() {
    //WARNING !!!!
    //Working on the sprites!!
    
    this->currentFrame = sf::IntRect(0, 0, 64,64);

    if(!this->main_hero_texture.loadFromFile("/home/crocus/game_project/game_sprites/main_hero/Player_Advanced/all_playerinverted.png")) {
        std::cout << "COUDLN'T LOAD PLAYER SHEET!" << "\n";
    }

    this->main_hero_sprite.setPosition(25.f, 340.f);
    this->main_hero_sprite.setTexture(this->main_hero_texture);
    this->main_hero_sprite.setTextureRect(this->currentFrame);
    this->main_hero_sprite.setScale(4.5f, 4.5f);
}

void Hero::keyboardMovement() {
    this->animations_number = HERO_ANIMATION::IDLE;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        this->moving(-1.f, 0.f);
        this->animations_number = HERO_ANIMATION::MOVING_LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        this->moving(1.f, 0.f);
        this->animations_number = HERO_ANIMATION::MOVING_RIGHT;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        this->moving(0.f, -1.f);
        this->animations_number = HERO_ANIMATION::JUMPING;
    }
}

void Hero::initAnimations() {
    this->heroAnimationTimer.restart();
}


void Hero::initPhysics() {
    this->maxVelocity = 10.f;
    this->minVelocity = 1.f;
    this->acceleration = 3.f;
    this->drag = 0.50f;
    this->gravity = 2;
    this->maxGravitySpeed = 6.f;
}
void Hero::moving(const float dir_x, const float dir_y) {
    // Acceleration
    this->velocity.x += dir_x * this->acceleration;
    
    // Limit velocity
    if(std::abs(this->velocity.x) > this->maxVelocity) {
        this->velocity.x = this->maxVelocity * ((this->velocity.x) ? -1.f : 1.f);
    }

}
void Hero::updatePhysics() {
    // Deceleration
    this->velocity *= this->drag;


    // Limit decceleration
    if(std::abs(this->velocity.x) < this->minVelocity) {
        this->velocity.x = 0.f;
    }
    else if(std::abs(this->velocity.y) < this->minVelocity) {
        this->velocity.y = 0.f;
    }
    this->main_hero_sprite.move(this->velocity);

    //Gravity
    this->velocity.y += 1.0 * this->gravity;
    if(std::abs(this->velocity.y) > this->maxGravitySpeed) {
        this->velocity.y = this->maxGravitySpeed * ((this->velocity.y) ? -1.f : 1.f);
    }
}


void Hero::updateAnimations() {

    //DANGEOURS !!!!!!!!!!!!!!!!!!!
    //WORKING ON ANIMATIONS 

    if(this->animations_number == HERO_ANIMATION::IDLE) {
        if(this->heroAnimationTimer.getElapsedTime().asSeconds() >= 0.2f) {
            this->currentFrame.top = 0.f;
            this->currentFrame.left+= 64.f; 
            if(this->currentFrame.left >= 266.f) {
                this->currentFrame.left = 0;
            }

            this->heroAnimationTimer.restart();
            this->main_hero_sprite.setTextureRect(this->currentFrame);
        }
    }    
    else if(this->animations_number == HERO_ANIMATION::MOVING_RIGHT) {
        if(this->heroAnimationTimer.getElapsedTime().asSeconds() >= 0.1f) {
            this->currentFrame.top = 64.f;
            this->currentFrame.left+= 64.f; 
            if(this->currentFrame.left >= 266.f) {
                this->currentFrame.left = 0;
            }

            this->heroAnimationTimer.restart();
            this->main_hero_sprite.setTextureRect(this->currentFrame);

        }
    }    
    else if(this->animations_number == HERO_ANIMATION::MOVING_LEFT) {
        if(this->heroAnimationTimer.getElapsedTime().asSeconds() >= 0.1f) {
            this->currentFrame.top = 365.f;
            this->currentFrame.left+= 64.f; 
            if(this->currentFrame.left >= 266.f) {
                this->currentFrame.left = 0;
            }

            this->heroAnimationTimer.restart();
            this->main_hero_sprite.setTextureRect(this->currentFrame);

        }
    }    
    // check the collision with window
    if(this->getHeroPositionY()> 380.f) { 
        if(this->getHeroPositionX() < -50.f)
            this->main_hero_sprite.setPosition(-50.f, 380.f);
        else if(this->getHeroPositionX() > 8400.f)
            this->main_hero_sprite.setPosition(8400.f, 380.f);
        else
            this->main_hero_sprite.setPosition(this->getHeroPositionX(), 380.f);
    }
}

void Hero::updateHeroPosition() {
    hero_position = main_hero_sprite.getPosition();
}
float Hero::getHeroPositionX() {
    return hero_position.x;
}
float Hero::getHeroPositionY() {
    return hero_position.y;
}
