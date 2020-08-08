#include "gameengine.h"
#include "gamestate.h"

void GameEngine::Start(const char* title, int width, int height,
	bool fullscreen) {
	
	int screen_style;

	if (fullscreen) {
		screen_style = sf::Style::Fullscreen;
	}
	else {
		screen_style = sf::Style::Default;
	}

	// begin initializing our window
	sf::RenderWindow window(sf::VideoMode(width, height), title, screen_style);

	m_fullscreen = fullscreen;
	m_running = true;

	printf("GameEngine initialized.\n");

}

void GameEngine::Cleanup() {

	// cleanup state stack
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// destroy our window
	window->close();

}

void GameEngine::ChangeState(GameState* state) {

	// clean and remove current state from stack
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and Start new state
	states.push_back(state);
	states.back()->Start();
}

void GameEngine::PushState(GameState* state) {
	
	// pause current state
	if (!states.empty()) {
		states.back()->Pause();
	}

	// add new state to stack and Start it
	states.push_back(state);
	states.back()->Start();

}

void GameEngine::PopState() {

	// clean and remove current state from stack
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty()) {
		states.back()->Resume();
	}
}

void GameEngine::HandleEvents() {

	// delegate event handling to the state
	states.back()->HandleEvents(this);
}

void GameEngine::Update() {
	// delegate updating to the state
	states.back()->Update(this);
}

void GameEngine::Draw() {
	// delgate drawing to the state
	states.back()->Draw(this);
}
