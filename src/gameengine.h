#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class GameState;

class GameEngine {
public:
	void Start(sf::RenderWindow& window, int width = 640, int height = 480,
		       bool fullscreen = false);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	sf::RenderWindow* m_window;

private:
	// our state stack
	vector<GameState*> states;

	bool m_running;
	bool m_fullscreen;
};
