#include "gameengine.h"
#include "playingstate.h"

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

}

void PlayingState::Draw(GameEngine* engine) {

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	engine->m_window->clear();
	engine->m_window->draw(shape);
	engine->m_window->display();
}