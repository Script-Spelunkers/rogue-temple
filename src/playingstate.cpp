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

PlayingState PlayingState::m_PlayingState;

void PlayingState::Start() {
	printf("PlayingState Start");

	//Set Origins:
	bb1.setOrigin(50.0f, 50.0f);
	bb2.setOrigin(50.0f, 50.0f);


	//Set Initial Fill Color: 
	bb1.setFillColor(sf::Color::White);
	bb2.setFillColor(sf::Color::Blue);

	//Set init position:
	bb1.setPosition(100.0f, 0.0f);
	bb2.setPosition(95.0f, 250.0f);

	bb1.setRotation(37.0f);
	bb2.setRotation(87.0f);

}

void PlayingState::Cleanup() {
	printf("PlayingState Cleanup");
}

void PlayingState::Pause() {
	printf("PlayingState Pause");
}

void PlayingState::Resume() {
	printf("PlayingState Resume");
}

void PlayingState::HandleEvents(GameEngine* engine) {
	sf::Event event;
	if (engine->m_window->pollEvent(event)) {
	if (event.type == sf::Event::Closed) {
			engine->Quit();
		}
	}
}

void PlayingState::Update(GameEngine* engine) {


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

void PlayingState::Draw(GameEngine* engine) {

	this->draws_called++;
	printf("Draw Call Num: %d\n", this->draws_called);
	printf("***************\n");

	engine->m_window->clear();
	engine->m_window->draw(bb1);
	engine->m_window->draw(bb2);

	engine->m_window->display();
}
