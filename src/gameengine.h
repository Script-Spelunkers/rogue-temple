#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class GameState;

class GameEngine {
public:
	void start(const char* title, int width = 640, int height = 480,
		       bool fullscreen = false);
	void cleanup();

	void changeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void handleEvents();
	void update();
	void draw();

	bool Running() { return _running; }
	void Quit() { _running = false; }

	sf::RenderWindow* _window;

private:
	// our state stack
	vector<GameState*> states;

	bool _running;
	bool m_fullscreen;
};
