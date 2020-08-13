#pragma once

#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "boundingbox.h"
#include "aabbintersector.h"
#include <vector>


class PlayingState : public GameState {
public:

	//TODO REMOVE: 
	int draws_called = 0;

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