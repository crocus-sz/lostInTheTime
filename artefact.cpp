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
    else if(artefact_name == "Tomato") {
        path_to_animation = "/home/crocus/game_project/game_sprites/another_stuff/Food/Tomato.png";
    }
    else if(artefact_name == "Shrimp") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Shrimp.png";
    }
    else if(artefact_name == "Sushi") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Sushi.png";
    }
    else if(artefact_name == "Sashimi") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Sashimi.png";
    }
    else if(artefact_name == "Sardines") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Sardines.png";
    }
    else if(artefact_name == "Pretzel") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Pretzel.png";
    }
    else if(artefact_name == "Pickle") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Pickle.png";
    }
    else if(artefact_name == "Peach") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Peach.png";
    }
    else if(artefact_name == "Onion") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Onion.png";
    }
    else if(artefact_name == "Olive") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Olive.png";
    }
    else if(artefact_name == "MelonWater") {
        path_to_animation  = "/home/crocus/game_project/game_sprites/another_stuff/Food/Olive.png";
    }
}


void Artefact::updateAnimations() {

}

bool Artefact::isDestroyedFunc() {
    return isDestroyed;
}
void Artefact::destroyArtefact() {
    this->isDestroyed = true;
}

float Artefact::getArtefactPositionX() {
    float x = artefact_position.x;
    return x;
}

