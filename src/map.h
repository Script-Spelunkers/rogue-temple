#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "tile.h"
#pragma once
//Class that holds a 2 dimensional array of Tiles:
//Map will get sub-divided into regions for BSP:
//Place Room in each region based on region's size, connect the rooms:
//?????
//Profit: 
class Map{

    public:
        //Pointer to a Tile Object: We allocate the array of this dynamically using new:
        //Remember to clean up your memory kuuls. :)
        Tile ** _arr;

        //Constructor:
        Map(int rows, int cols, float size);

        //Get a specific Tile: (For Drawing):
        Tile getTile(int x, int y);

        //Get total rows:
        int getRows();
        //Get total cols:
        int getCols();
        //Deconstructor:
        ~Map();


    private:
        //Needed so you can free memory later:
        int rows;
        int cols;


};

