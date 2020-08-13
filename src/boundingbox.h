#pragma once

using namespace std;


//IMPORTANT DEFINITIONS:
//AABB: AXIS ALIGNED BOUNDING BOX: Means the box is not rotated: Requires few checks:
//NON-AABB: NON-AXIS ALIGNED BOUNDING BOX: Means the box is rotated: Requires many checks: 

//BOUNDING BOX REPRESENTATION:
//(x, y)                                    (x + width, y)

//                  (c_x, c_y)

//(x, y + height)    `                      (x + width, y + height)


//Given 2 points, a width, and a height, we can calculate if two AABB boxes overlap by performing 4 checks:
//The center is used to check non AABB boxes:

//A "transform" can be applied upon a bounding box: A transform in effect is a math operation that is applied over all points via a for loop:
//A transform of +2 in the x direction will move all points +2 in the x direction:
//Everything that is movable in the game will require a transform list: I keep my lists as follows:

//x_offset
//y_offset
//z_offset

//Only used in 3D and non AABB physics:

//x_rot
//y_rot
//z_rot





//Class designed to represent an AABB bounding box:
//AABB is relatively cheap to process, at the cost of not utilizing space well:
class aabb_bounding_box{

    //
    public:
        aabb_bounding_box(float x, float y, float width, float height, bool active, bool draw){

            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
            this->active = active;
            this->draw = draw;

        }   

        float getX();
        float getY();

        float getWidth();
        float getHeight();

        bool getActive();
        bool getDraw();

        void setX(float x);
        void setY(float y);


    //
    protected:
    
        float x;
        float width;

        float y;
        float height;


        bool active;    //determines if it should be active, i.e considered by the physics engine: (change to an int for states????)
        bool draw;      //determines if it should be drawn by the renderer: Line Draw process TBD:

};



//Class designed to represent a non AABB bounding box:
//Non AABB can represent space well due to rotations, but requires higher processing power:
//class non_aabb_bounding_box(){





//};
