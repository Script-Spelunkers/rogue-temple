#pragma once

#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "entity.h"
#include <vector>

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
    vector<Entity*> _entity_container;
};
