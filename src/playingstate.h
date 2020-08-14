#pragma once

#include "gamestate.h"

class PlayingState : public GameState {
public:
	virtual void start();
	virtual void cleanup();

	virtual void pause();
	virtual void resume();

	virtual void handleEvents(GameEngine* engine);
	virtual void update(GameEngine* engine);
	virtual void draw(GameEngine* engine);

	// method to get our singleton
	static PlayingState* GetInstance() {
		return &_playing_state;
	}

private:
	PlayingState() { };
	static PlayingState _playing_state;
};