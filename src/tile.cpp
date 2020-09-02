#include "tile.h"
#include <iostream>

//Dummy Constructor to satisfy Compiler:
Tile::Tile(){


}

//Main Constructor:
Tile::Tile(int x, int y, float size, TileType t){

    this->_x = x;
    this->_y = y;
    this->_type = t;
    this->_rect.setSize(sf::Vector2f(size, size));



    //Todo: talk about translates to justin:
    //Compiler ISTG:
    float x_flo = x;
    float y_flo = y;
    this->_rect.setPosition(x_flo * size, y_flo * size);

    //Fill the Rect, or set its texture:
    this->setGraphic();

}

//Start of Getter Functions: 
int Tile::getX(){

    return this->_x;

}

int Tile::getY(){

    return this->_y;

}

TileType Tile::getType(){

    return this->_type;

}

sf::RectangleShape Tile::getRect(){

    return this->_rect;

}

void Tile::setType(TileType t){

    this->_type = t;
    this->setGraphic();

}

void Tile::setGraphic(){

    switch(this->_type){

        //
        case Unplaced: 
        this->_rect.setFillColor(sf::Color::White);       
        break;
        //

        case Darkness: 
        this->_rect.setFillColor(sf::Color::Black);       
        break;

        //
        case Grass: 
        this->_rect.setFillColor(sf::Color::Green);          
        break;

        //
        case Water: 
        this->_rect.setFillColor(sf::Color::Blue); 
        break;
        
        //
        case Rock: 
        this->_rect.setFillColor(sf::Color::Cyan); 
        break;

        //
        default: printf("Not supported Tile Type: Ooooweeee:\n");
    
    }

}