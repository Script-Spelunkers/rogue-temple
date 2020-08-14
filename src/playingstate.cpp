#include "gameengine.h"
#include "playingstate.h"
#include "boundingbox.h"
#include <iostream>


//Globals cos its 12 am: sue me:
//These need to be incorporated into the Entity class: Everything should go through there:
sf::RectangleShape rect_1(sf::Vector2f(120.f, 50.f));
sf::RectangleShape rect_2(sf::Vector2f(120.f, 50.f));

sf::RectangleShape bb1(sf::Vector2f(120.f, 50.f));
sf::RectangleShape bb2(sf::Vector2f(120.f, 50.f));

bool intersecting = false;
aabbIntersector intersector_tester;
float y_nought = rect_1.getPosition().y;


PlayingState PlayingState::m_PlayingState;

void PlayingState::Start() {
	printf("PlayingState Start");
	bb2.setPosition(0, 125.0f);
    rect_2.setPosition(0, 125.0f);
    rect_2.setFillColor(sf::Color::Blue);
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

		intersecting = intersector_tester.check_aabb_intersection(bb1, bb2);
		if(intersecting){

			rect_1.setFillColor(sf::Color::Green);
			rect_1.move(0.0, .2);
			bb1.move(0.0, .2);

		}else{
		    rect_1.setFillColor(sf::Color::White);
			rect_1.move(0.0, .2);
			bb1.move(0.0, .2);

		}

	}



}

void PlayingState::Draw(GameEngine* engine) {

	this->draws_called++;
	printf("Draw Call Num: %d\n", this->draws_called);
	printf("***************\n");

	engine->m_window->clear();
	engine->m_window->draw(rect_1);
	engine->m_window->draw(rect_2);

	engine->m_window->display();
}
