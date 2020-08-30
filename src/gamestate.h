#pragma once

#include "gameengine.h"

class GameState {
public:
    virtual void start() = 0;
    virtual void cleanup() = 0;

    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void handleEvents(GameEngine* engine) = 0;
    virtual void update(GameEngine* engine) = 0;
    virtual void draw(GameEngine* engine) = 0;

    void changeState(GameEngine* engine, GameState* state) {
        engine->changeState(state);
    }

protected:
    GameState() { }
};
