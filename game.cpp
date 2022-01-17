// this file is cpp realization of game.h an elementary game "engine"

#include "game.h"
#include <iostream>

#define WIDTH 900
#define HEIGHT 600

Game::Game() {
    this->init_window();
    this->initPlayer();
    this->initBackground();
    this->initArtefact();
}

Game::~Game() {
    delete this->window;
    delete this->main_hero;
    delete this->artefact;
}


void Game::render() {
    //clear old frame
    //render objects
    //display frame in window
    
    this->window->setView(hero_view);
    this->window->clear();
    this->renderBackground();
    this->renderHero();
    if(!artefact->isDestroyedFunc()) {
       this->renderArtefact();
    }
    this->updateView(main_hero->getHeroPositionX(), main_hero->getHeroPositionY());
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

void Game::initArtefact() {
    artefact = new Artefact(400, main_hero->getHeroPositionY()+500, "Waffles", 5);
}

void Game::renderArtefact() {
    artefact->render(*window);
    this->collisionHeroWithArtefact();
}
void Game::collisionHeroWithArtefact() {
    if(artefact->getArtefactPositionX() - main_hero->getHeroPositionX() < 120) { 
        artefact->destroyArtefact();
    }
}
