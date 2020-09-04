#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager {
private:
    static AssetManager* _static_instance;
    std::map<std::string, sf::Texture*> _textures;
    AssetManager();
    ~AssetManager();

public:
    static AssetManager* getInstance(); 
    void release(); // release this instance of asset manager

    sf::Texture* getTexture(std::string filename);
};
