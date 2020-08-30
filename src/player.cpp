#include "player.h"

Player::Player() {
    _texture.loadFromFile("../assets/spritesheets/test.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(10, 10, 256, 256));
    _x = 0;
    _y = 0;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite);
}

void Player::update() {

}
