#pragma once
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace std;


// Class is designed to test intersections between aabb bounding boxes:
// See boundingbox.h for more details on class def of a bounding box:
// Other notes: Note that a single entity may have more then 1 bounding box:
// This can occur for complex entities, and entities with projectile weapons:
// As game gets fleshed out, so do the underlying properties:
//
class physics_intersector{

    //
    public:
        bool check_aabb_intersection(sf::RectangleShape &A, sf::RectangleShape &B);


};
