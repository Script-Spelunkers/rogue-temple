#include "gameengine.h"
#include "playingstate.h"
#include "physics_intersector.h"
#include <iostream>


//****************************************************************************************
//Globals cos its 12 am: sue me:
//These need to be incorporated into the Entity class: Everything should go through there:
sf::RectangleShape bb1(sf::Vector2f(100.0f, 100.0f));
sf::RectangleShape bb2(sf::Vector2f(67.0f, 100.0f));
bool intersecting = false;
physics_intersector intersector_tester;
//****************************************************************************************

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
	if (engine->m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			engine->Quit();
		}
	}
}

void PlayingState::update(GameEngine* engine) {


	//prevents weird transform memery: will figure out later ;)
	if(this->draws_called > 10){

		intersecting = intersector_tester.check_rect_rect_intersection(bb1, bb2);
		if(intersecting){

			bb1.setFillColor(sf::Color::Green);
			bb1.move(0.0, 1.0);

		}else{
		    bb1.setFillColor(sf::Color::White);
			bb1.move(0.0, 1.0);

		}


	//if(this->draws_called > 50){

		//bb2.setRotation(bb2.getRotation() + 1);

	//}



	}
	
}

void PlayingState::draw(GameEngine* engine) {

	this->draws_called++;
	printf("Draw Call Num: %d\n", this->draws_called);
	printf("***************\n");

	engine->_window->clear();
	engine->_window->draw(shape);
	engine->_window->display();
}
