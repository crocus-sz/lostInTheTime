// this file is cpp realization of game.h an elementary game "engine"

#include "game.h"
#include <iostream>
#include <string>

#define WIDTH 900
#define HEIGHT 600

Game::Game() {
    this->init_window();
    this->initPlayer();
    this->initBackground();
    this->initAllArtefact();
    //this->initTextBox();
    this->initText();
}

Game::~Game() {
    delete this->window;
    delete this->main_hero;
    delete this->artefact;
    delete this->artefact1;
}


void Game::render() {
    //clear old frame
    //render objects
    //display frame in window
    
    this->window->setView(hero_view);
    this->window->clear();
    this->renderBackground();
    this->renderHero();
    this->renderText();
    if(!artefact->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact);
    }
    if(!artefact1->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact1);
    }
    this->updateView(main_hero->getHeroPositionX(), main_hero->getHeroPositionY());
    //this->renderTextBox();
    this->window->display();
}


void Game::init_window() {
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
    this->initView();

}
void Game::initView() {
    hero_view.reset(sf::FloatRect(0, 0, WIDTH, HEIGHT));
}

void Game::updateView(float x, float y) {
    sf::Vector2f position;
    if(x + 10  > WIDTH / 2) {
        position.x = x + 10;
    }
    else {
        position.x = (WIDTH / 2);
    }
    position.y = y-80;
    hero_view.setCenter(position);
}

const bool Game::isRunning() {
    return this->window->isOpen();
}

void Game::update() {
      while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                window->close();
        }
      this->updateHero();
}

void Game::updateHero() {
    this->main_hero->update();
}

void Game::initPlayer() {
    this->main_hero = new Hero();
    this->counter_hero = 0;
}

void Game::renderHero() {
    this->main_hero->render(*window);
}

void Game::initBackground() {
    if(!this->background_texture1.loadFromFile("/home/crocus/game_project/game_sprites/maps/cyberpunk-street-files/PNG/cyberpunk-street1.png")) {
        std::cout << "ERROR! COULDN'T LOAD A BACKGROUND" << std::endl;
    }
    else {
        this->background_sprite1.setTexture(background_texture1);
        this->background_sprite1.setScale(WIDTH*10/background_sprite1.getLocalBounds().width, HEIGHT/background_sprite1.getLocalBounds().height);
    }
}

void Game::renderBackground() {
    window->draw(background_sprite1);
}

void Game::initAllArtefact() {
    artefact = new Artefact(400, main_hero->getHeroPositionY()+500, "Waffles", 5);
    artefact1 = new Artefact(700, main_hero->getHeroPositionY()+500, "Shrimp", 5);
}

void Game::renderOneArtefact(Artefact &artefact_num) {
    artefact_num.render(*window);
    this->collisionHeroWithArtefact(artefact_num);
}
void Game::collisionHeroWithArtefact(Artefact &artefact_num) {
    if(artefact_num.getArtefactPositionX() - main_hero->getHeroPositionX() < 120) { 
        artefact_num.destroyArtefact();
        this->updateCounter();
    }
}

void Game::initTextBox() {
    if(!this->textbox_texture.loadFromFile("/home/crocus/game_project/game_sprites/another_stuff/ramka_10_prod_jedz.png")) {
        std::cout << "ERROR! COULDN'T LOAD A BACKGROUND" << std::endl;
    }
    else {
        this->textbox_sprite.setTexture(textbox_texture);
        this->textbox_sprite.setScale(0.4f, 0.3f);
    
    }
}
void Game::renderTextBox() {
    window->draw(textbox_sprite);
}

void Game::updateCounter() {
    this->counter_hero += 1;
    this->updateText(counter_hero);
}

void Game::initText() {
    if(!font.loadFromFile("/home/crocus/game_project/game_sprites/another_stuff/PressStart2P-Regular.ttf")) {
        std::cout << "COUDLNT NOT LOAD A FONT!" << std::endl;
    }
    counter_text.setFont(font);
    counter_text.setCharacterSize(24);

    std::string counter_string = std::to_string (counter_hero);
    counter_text.setString(counter_string);
    
}
void Game::renderText() {
    window->draw(counter_text);
}
void Game::updateText(int new_count) {
    std::string counter_string = std::to_string (new_count);
    counter_text.setString(counter_string);
}
