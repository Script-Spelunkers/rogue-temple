#include "gameengine.h"
#include "gamestate.h"

void GameEngine::start(const char* title, int width, int height,
    bool fullscreen) {
    
    int screen_style;

    if (fullscreen) {
        screen_style = sf::Style::Fullscreen;
    }
    else {
        screen_style = sf::Style::Default;
    }

    _full_screen = fullscreen;
    _running = true;

    _window = new sf::RenderWindow(sf::VideoMode(width, height), title);

    printf("GameEngine initialized.\n");

}

void GameEngine::cleanup() {

    // cleanup state stack
    while (!states.empty()) {
        states.back()->cleanup();
        states.pop_back();
    }

    // destroy our window
    _window->close();
    delete _window;

}

void GameEngine::changeState(GameState* state) {

    // clean and remove current state from stack
    if (!states.empty()) {
        states.back()->cleanup();
        states.pop_back();
    }

    // store and start new state
    states.push_back(state);
    states.back()->start();
}

void GameEngine::PushState(GameState* state) {
    
    // pause current state
    if (!states.empty()) {
        states.back()->pause();
    }

    // add new state to stack and start it
    states.push_back(state);
    states.back()->start();

}

void GameEngine::PopState() {

    // clean and remove current state from stack
    if (!states.empty()) {
        states.back()->cleanup();
        states.pop_back();
    }

    // resume previous state
    if (!states.empty()) {
        states.back()->resume();
    }
}

void GameEngine::handleEvents() {

    // delegate event handling to the state
    states.back()->handleEvents(this);
}

void GameEngine::update() {
    // delegate updating to the state
    states.back()->update(this);
}

void GameEngine::draw() {
    // delgate drawing to the state
    states.back()->draw(this);
}
