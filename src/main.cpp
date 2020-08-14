#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "playingstate.h"

#include <iostream>

int main()
{
    GameEngine engine;
    engine.start( "GameEngine Pre-Alpha v1.0" );

    engine.changeState(PlayingState::GetInstance());

    while (engine.Running())
    {
        engine.handleEvents();
        engine.update();
        engine.draw();
    }

    engine.cleanup();

    return 0;
}