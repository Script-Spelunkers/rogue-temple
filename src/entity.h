#pragma once

#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable {
public:
    Entity() = default;
    explicit Entity(sf::Sprite& sprite) : _sprite(sprite) {};
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
    virtual void update() = 0;

    // TODO virtual void handleInput(const inputData &input) {};

protected:
    sf::Texture _texture;
    sf::Sprite _sprite;

};
