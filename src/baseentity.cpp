#include "baseentity.h"
#include "boundingbox.h"

int baseentity::get_EID(){

    return this->e_id;

}

void baseentity::set_EID(int x){


    this->e_id = x;

}


aabb_bounding_box* baseentity::getBounds(){

  return this->bounds;

}
