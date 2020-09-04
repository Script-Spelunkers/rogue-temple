#pragma once
#include "SFML/Graphics.hpp"
#include "assetmanager.h"

class Entity : public sf::Drawable {
public:
    Entity() {};
    explicit Entity(int x, int y) : _x(x), _y(y) {};
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
    virtual void update() = 0;

    // TODO virtual void handleInput(const inputData &input) {};

protected:
    sf::Texture* _texture;
    sf::Sprite _sprite;

    int _x;
    int _y;

};
