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
    this->initTextBox();
    this->initTextBoxCompleteTask();
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
    if(!artefact2->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact2);
    }
    if(!artefact3->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact3);
    }
    if(!artefact4->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact4);
    }
    if(!artefact5->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact5);
    }
    if(!artefact6->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact6);
    }
    if(!artefact7->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact7);
    }
    if(!artefact8->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact8);
    }
    if(!artefact9->isDestroyedFunc()) {
        this->renderOneArtefact(*artefact9);
    }
    this->updateView(main_hero->getHeroPositionX(), main_hero->getHeroPositionY());
    if(this->isTaskBoxVisible) {
        this->renderTextBox();
    }
    if(this->isCompleteTaskBoxVisible) {
        this->renderTextBoxCompleteTask();
    }
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
    this->moveText(position);
    this->moveTextBox(position);
    this->moveTextBoxCompleteTask(position);
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
      this->showTask();
      this->closeTask();
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
    artefact = new Artefact(1100, main_hero->getHeroPositionY()+500, "Waffles", 5);
    artefact1 = new Artefact(1700, main_hero->getHeroPositionY()+500, "Shrimp", 5);
    artefact2 = new Artefact(2300, main_hero->getHeroPositionY()+500, "Tomato", 5);
    artefact3 = new Artefact(2700, main_hero->getHeroPositionY()+500, "Sashimi", 5);
    artefact4 = new Artefact(3100, main_hero->getHeroPositionY()+500, "Sardines", 5);
    artefact5 = new Artefact(3500, main_hero->getHeroPositionY()+500, "Pretzel", 5);
    artefact6 = new Artefact(3900, main_hero->getHeroPositionY()+500, "Pickle", 5);
    artefact7 = new Artefact(4500, main_hero->getHeroPositionY()+500, "Peach", 5);
    artefact8 = new Artefact(4900, main_hero->getHeroPositionY()+500, "Onion", 5);
    artefact9 = new Artefact(5500, main_hero->getHeroPositionY()+500, "Olive", 5);
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
    isTaskBoxVisible = false;
    if(!this->textbox_texture.loadFromFile("/home/crocus/game_project/game_sprites/another_stuff/robot_border_10_artefacts.png")) {
        std::cout << "ERROR! COULDN'T LOAD A BACKGROUND" << std::endl;
    }
    else {
        this->textbox_sprite.setTexture(textbox_texture);
        this->textbox_sprite.setScale(0.8f, 0.8f);
    
    }
}
void Game::renderTextBox() {
    window->draw(textbox_sprite);
}

void Game::updateCounter() {
    this->counter_hero += 1;
    this->updateText(counter_hero);
    this->updateTextBox();
}

void Game::initText() {
    if(!font.loadFromFile("/home/crocus/game_project/game_sprites/another_stuff/PressStart2P-Regular.ttf")) {
        std::cout << "COUDLNT NOT LOAD A FONT!" << std::endl;
    }
    counter_text.setFont(font);
    counter_text.setCharacterSize(15);

    std::string counter_string = std::to_string (counter_hero);
    counter_text.setString("artefacts: " + counter_string);
    
}
void Game::renderText() {
    window->draw(counter_text);
}
void Game::updateText(int new_count) {
    std::string counter_string = std::to_string (new_count);
    counter_text.setString("artefacts: " + counter_string);
}
void Game::moveText(sf::Vector2f position) {
    position.x -= 440;
    position.y -= 290;
    counter_text.setPosition(position);
}
void Game::showTask() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
        isTaskBoxVisible = true;
    }
}
void Game::closeTask() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        isTaskBoxVisible = false;
        isCompleteTaskBoxVisible = false;
    }
}
void Game::moveTextBox(sf::Vector2f position) {
    position.x -= 200;
    position.y -= 200;
    textbox_sprite.setPosition(position);

}
void Game::initTextBoxCompleteTask() {
    isCompleteTaskBoxVisible = false;
    if(!this->complete_task_texture.loadFromFile("/home/crocus/game_project/game_sprites/another_stuff/completed_task.png")) {
        std::cout << "ERROR! COULDN'T LOAD A COMPLETE TASK TEXTURE" << std::endl;
    }
    else {
        this->complete_task_sprite.setTexture(complete_task_texture);
        this->complete_task_sprite.setScale(0.5f, 0.5f);
    
    }
}
void Game::renderTextBoxCompleteTask() {
    window->draw(complete_task_sprite);
}
void Game::moveTextBoxCompleteTask(sf::Vector2f position) {
    position.x -= 200;
    position.y -= 200;
    complete_task_sprite.setPosition(position);

}

void Game::updateTextBox() {
    if(counter_hero == 10) {
        this->textbox_texture.loadFromFile("/home/crocus/game_project/game_sprites/another_stuff/robot_border_gohome.png");
        this->textbox_sprite.setTexture(textbox_texture);
        isCompleteTaskBoxVisible = true;
    }
}
