// this file is a elementary game "engine"
#ifndef GAME_H
#define GAME_H



#include "main_hero.h"
#include "artefact.h"
#include "all_incl.h"



class Game {
    private:
        sf::RenderWindow *window;
        sf::Event event;
        sf::VideoMode videoMode;
        sf::Vector2u texture_size;
        sf::View hero_view;
        int counter_hero;
        sf::Text counter_text;
        sf::Font font;
        bool isTaskBoxVisible;



        //Background
        sf::Texture background_texture1, textbox_texture;
        sf::Sprite background_sprite1, textbox_sprite;
        void initBackground();
        void initTextBox();
        void renderTextBox();
        void moveTextBox(sf::Vector2f position);
        void showTask();
        void closeTask();
        void renderBackground();
        void repeatBackground();
        
        void init_window();
        void initPlayer();
        void initAllArtefact();
        void initStatusbar();
        void initText();
        Hero *main_hero;
        Artefact *artefact;
        Artefact *artefact1;
        

    public:
        Game();
        virtual ~Game();

        void update();
        void render();
        void updateHero();
        void renderHero();
        void updateArtefact();
        void renderOneArtefact(Artefact &artefact_num);
        void updateStatusBar();
        void renderStatusbar();
        void renderText();
        void updateText(int new_count);
        void moveText(sf::Vector2f position);

        void updateCounter();

        const bool isRunning();
        void initView();
        sf::View returnView();
        void moveView(float x, float y);
        void updateView(float x, float y);


        void collisionHeroWithArtefact(Artefact &artefact_num);
};
#endif 
