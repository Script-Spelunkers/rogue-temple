#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "playingstate.h"

#include <iostream>

int main()
{
    GameEngine engine;
    engine.Start( "GameEngine Pre-Alpha v1.0" );

    engine.ChangeState(PlayingState::GetInstance());

    while (engine.Running())
    {
        engine.HandleEvents();
        engine.Update();
        engine.Draw();
    }

    engine.Cleanup();

    return 0;
}