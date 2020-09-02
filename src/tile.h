#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#pragma once


//Determines what the tile is:
//Unplaced is how the Tiles will be instantiated:
//Darkness is a black screen:
//Grass is Grass:
//Water is Water:
//Rock is Rock:
//Need to divvy these up into subtiles based on interactions / half tiles:
//:3
enum TileType{Unplaced, Darkness, Grass, Water, Rock};


//Will be the basis of our map:
//
class Tile{

    public:
        Tile();
        Tile(int x, int y, float size, TileType t);
        int getX();
        int getY();
        TileType getType();
        void setType(TileType t);
        void setGraphic();
        sf::RectangleShape getRect();


    private:
        TileType _type;
        sf::RectangleShape _rect;
        unsigned int _x;
        unsigned int _y;



};

