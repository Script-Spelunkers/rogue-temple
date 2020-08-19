#include "gameengine.h"
#include "playingstate.h"
#include "physics_intersector.h"
#include <iostream>

PlayingState PlayingState::_playing_state;

void PlayingState::start() {
	printf("PlayingState start");
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
	engine->_window->display();

}
