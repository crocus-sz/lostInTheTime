#ifndef ART_H
#define ART_H 

#include "all_incl.h"


class Artefact {

    private:
        sf::Sprite artefact_sprite;
        sf::Texture artefact_texture;
        sf::Vector2f artefact_position;
        std::string artefact_name;
        int artefact_amount;
        std::string path_to_animation;
        sf::IntRect currentFrame;

    public:
        Artefact(float posX, float posY, std::string name, int amount);
        ~Artefact();
        void initAnimations();
        void chooseAnimations();
        void updateAnimations();
        void render(sf::RenderWindow &win);
        void destroyArtefact();
        float getArtefactPositionX();
        bool isDestroyedFunc();


        bool isDestroyed;
};

#endif
