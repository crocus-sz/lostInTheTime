// this file is a elementary game "engine"
#ifndef GAME_H
#define GAME_H



#include "main_hero.h"
#include "all_incl.h"


class Game {
    private:
        sf::RenderWindow *window;
        sf::Event event;
        sf::VideoMode videoMode;
        sf::Vector2u texture_size;
        sf::View hero_view;


        //Background
        sf::Texture background_texture1, background_texture2, background_texture3;
        sf::Sprite background_sprite1, background_sprite2, background_sprite3;
        void initBackground();
        void renderBackground();
        void repeatBackground();
        
        void init_window();
        void initPlayer();
        Hero *main_hero;

    public:
        Game();
        virtual ~Game();

        void update();
        void render();
        void updateHero();
        void renderHero();

        const bool isRunning();
        void initView();
        sf::View returnView();
        void moveView(float x, float y);
        void updateView(float x, float y);
};
#endif 
