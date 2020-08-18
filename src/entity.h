#pragma once

#include "SFML/Graphics.hpp"

class Entity : sf::Drawable {
    virtual void draw(sf::RenderTarget target, sf::RenderStates states) = 0;
    virtual void update() = 0;
    int getEntityId() const { return _entity_id ;};

    // TODO virtual void handleInput(const inputData &input) {};

private:
    int _entity_id;
    sf::Sprite _sprite;

};
