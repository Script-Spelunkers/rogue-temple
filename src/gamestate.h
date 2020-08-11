#pragma once

#include "gameengine.h"

class GameState {
public:
	virtual void Start() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(GameEngine* engine) = 0;
	virtual void Update(GameEngine* engine) = 0;
	virtual void Draw(GameEngine* engine) = 0;

	void ChangeState(GameEngine* engine, GameState* state) {
		engine->ChangeState(state);
	}

protected:
	GameState() { }
};