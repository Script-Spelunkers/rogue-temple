#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "entity.h"

class Player: public Entity {
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update() override;
    Player(int x, int y);
};
