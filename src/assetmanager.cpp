#include "assetmanager.h"
#include <iostream>

AssetManager* AssetManager::_static_instance = NULL;

AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {
    for (auto texture : _textures) {
        if (texture.second != nullptr) {
            delete texture.second;
        }
    }
}

AssetManager* AssetManager::getInstance() {
    if (_static_instance == NULL) 
        _static_instance = new AssetManager();

    return _static_instance;
}

void AssetManager::release() {
    delete _static_instance;
    _static_instance = NULL;
}

sf::Texture* AssetManager::getTexture(std::string filename) {
    // TODO: fix this, get path from a specific dir
    std::string full_path = "../assets/spritesheets/";

    full_path.append(filename);

    // load the texture if not found
    if (_textures[full_path] == nullptr) {
        _textures[full_path] = new sf::Texture;
        _textures[full_path]->loadFromFile(full_path);
    }

    return _textures[full_path];
}
