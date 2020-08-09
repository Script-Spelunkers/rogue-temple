#pragma once

#include "gamestate.h"

class PlayingState : public GameState {
public:
	virtual void Start();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(GameEngine* engine);
	virtual void Update(GameEngine* engine);
	virtual void Draw(GameEngine* engine);

	// method to get our singleton
	static PlayingState* GetInstance() {
		return &m_PlayingState;
	}

private:
	PlayingState() { };
	static PlayingState m_PlayingState;
};