#include "map.h"




Map::Map(int rows, int cols, float size){


    //Used to help free memory later:
    //Also used to iterate through grid to draw:
    this->rows = rows;
    this->cols = cols;

    //Begin Allocating Memory:
    this->_arr = new Tile*[rows];
    for(int i = 0; i < rows; i++){

        this->_arr[i] = new Tile[cols];

    }

    //Create Default Tiles:
    int index = 0;
    while(index < rows){

        for(int j = 0; j < cols; j++){


            this->_arr[index][j] = Tile(index, j, size, TileType::Unplaced);

        }

        index++;
    
    }
}


//Deconstructor to free mem: 
//Inb4 mem leak regardless: 
Map::~Map(){

  for( int i = 0; i < this->rows; ++i ){
    
    delete[] this->_arr[i];
  
  }
  
  delete[] this->_arr;


}


Tile Map::getTile(int x, int y){

    return this->_arr[x][y];

}

int Map::getRows(){

    return this->rows;

}

int Map::getCols(){

    return this->cols;

}