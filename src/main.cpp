#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "playingstate.h"

#include <iostream>

int main()
{
    GameEngine engine;
    sf::RenderWindow window(sf::VideoMode(640, 480), "test");
    engine.Start(window);

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