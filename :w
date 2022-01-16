#include "artefact.h"

Artefact::Artefact(float posX, float posY, std::string name, int amount) {
    artefact_position.x = posX;
    artefact_position.y = posY;
    artefact_name = name;
    artefact_amount = amount;

    initAnimations();
    isDestroyed = false;

}

Artefact::~Artefact() {

}


void Artefact::initAnimations() {
    chooseAnimations();
    if(!artefact_texture.loadFromFile(path_to_animation)) {
        std::cout << "FAILED TO LOAD TEXTURE OF ARTEFACT" << std::endl;
    }
    else {
        artefact_sprite.setTexture(artefact_texture);
        artefact_sprite.setScale(4.5f, 4.5f);
        artefact_sprite.setPosition(artefact_position);
    }
}

void Artefact::render(sf::RenderWindow &win) {
    win.draw(artefact_sprite);
}

void Artefact::chooseAnimations() {
    if(artefact_name == "Waffles") {
        path_to_animation = "/home/crocus/game_project/game_sprites/another_stuff/Food/Waffles.png";
    }
    else if(artefact_name == "Stein") {
        path_to_animation = "/home/crocus/game_project/game_sprites/another_stuff/Food/Stein.png";
    }
    else if(artefact_name == "Shrimp") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Shrimp.png";
    }
}


void Artefact::updateAnimations() {

}

bool Artefact::isDestroyedFunc() {
    return isDestroyed;
}
void Artefact::destroyArtefact() {
    isDestroyed = true;
}

float Artefact::getArtefactPositionX() {
    float x = artefact_position.x;
    return x;
}

