#pragma once
#include "boundingbox.h"
#include <vector>

using namespace std;


//Abstract class that all entities are derived from:
//A class is made abstract by declaring at least one of its functions as Pure Virtual:

//REQUIRED READING: 
//https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php

//REQUIRED LISTENING :sunglasses:
//https://www.youtube.com/watch?v=uKUlkoEVzPQ


class baseentity{

    //
    public:

        //virtual void getBehavior() = 0;                                         //Placeholder Method that will be replaced as we flesh out the Entity Class:
        int get_EID();                                                          //Getter for the EID
        void set_EID(int x);                                                    //Setter for the EID: 
        aabb_bounding_box* getBounds();                                         //Getter for the bounding box: Convert to vector later: 


    //
    private:


    //
    protected:
        //Protected Var Definition:
        int e_id;                               //ID that allows the Engine to process the entity: Important that it is only set once, and not changed once set:
        aabb_bounding_box *bounds;              //Stores the Bounding box of an entity: Convert to a vector later: 


};  //End of the Line:
