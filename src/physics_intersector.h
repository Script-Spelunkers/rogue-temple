#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace std;


// Class is designed to test intersections between bounding boxes:
// Other notes: Note that a single entity may have more then 1 bounding box:
// This can occur for complex entities, and entities with projectile weapons:
// As game gets fleshed out, so do the underlying properties:
//
class physics_intersector{

    //
    public:
        bool check_rect_rect_intersection(sf::RectangleShape &A, sf::RectangleShape &B); 

    private:
        bool check_AABB_intersection_rects(sf::RectangleShape &A, sf::RectangleShape &B);
        bool check_SAT_intersection_rects(sf::RectangleShape &A, sf::RectangleShape &B);


};



//Helper Structs for AD: 
//
struct vec2d{
		
        float x;
		float y;
	
    
};

//Helper Polygon Struct
struct polygon{
		std::vector<vec2d> p;	// Vertexes:
		vec2d pos;				// Center of Shape:					
	};

