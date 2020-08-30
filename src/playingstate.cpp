#include "gameengine.h"
#include "playingstate.h"
#include "player.h"
#include "physics_intersector.h"
#include <iostream>

PlayingState PlayingState::_playing_state;

sf::Texture texture; // TODO: figure out where this should live
void PlayingState::start() {

    auto *player = new Player{50, 50};
    _entity_container.push_back(player);
}

void PlayingState::cleanup() {
    printf("PlayingState cleanup");
}

void PlayingState::pause() {
    printf("PlayingState pause");
}

void PlayingState::resume() {
    printf("PlayingState resume");
}

void PlayingState::handleEvents(GameEngine* engine) {
    sf::Event event;
    if (engine->_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            engine->Quit();
        }
    }
}

void PlayingState::update(GameEngine* engine) {

}	

void PlayingState::draw(GameEngine* engine) {

    engine->_window->clear();
    for (Entity* entity : this->_entity_container) {
        engine->_window->draw(*entity);
    }
    engine->_window->display();

}
