#include "gameengine.h"
#include "playingstate.h"
#include "boundingbox.h"



//Globals cos its 12 am: sue me:
//These need to be incorporated into the Entity class: Everything should go through there: 
sf::RectangleShape rect_1(sf::Vector2f(120.f, 50.f));
sf::RectangleShape rect_2(sf::Vector2f(120.f, 50.f));
aabb_bounding_box a_1(0, 1000, 120, 50, true, true);
aabb_bounding_box a_2(0, 300, 120, 50, true, true);
bool intersecting = false;
aabbIntersector intersector_tester;


PlayingState PlayingState::m_PlayingState;

void PlayingState::Start() {
	printf("PlayingState Start");
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

	int x_nought = a_1.getX();
	int y_nought = a_2.getY();
	//prevents weird transform memery: will figure out later ;)
	if(this->draws_called > 10){

		intersecting = intersector_tester.check_aabb_intersection(&a_1, &a_2);
		if(intersecting){

			rect_1.setFillColor(sf::Color::Green);

		}else{

			rect_1.move(0.0, 0.2f);
			y_nought = y_nought + 0.2;
			a_1.setY(y_nought);

		}

	}

	rect_2.setPosition(0, 125.0f);
	rect_2.setFillColor(sf::Color::Blue);

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
