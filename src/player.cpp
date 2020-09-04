#include "player.h"

Player::Player(int x, int y) {
    _texture = AssetManager::getInstance()->getTexture("test.png");
    _sprite.setTexture(*_texture);
    _x = x;
    _y = y;

    this->_sprite.setPosition(_x, _y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite);
}

void Player::update() {

}
