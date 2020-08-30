#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace std;

// Class is designed to test intersections between bounding boxes:
// Other notes: Note that a single entity may have more then 1 bounding box:
// This can occur for complex entities, and entities with projectile weapons:
// As game gets fleshed out, so do the underlying properties:
class PhysicsIntersector{

    public:
        bool checkRectangleIntersection(sf::RectangleShape &rectangle_a, sf::RectangleShape &rectangle_b); 
    
    private:
        bool checkAABBIntersection(sf::RectangleShape &rectangle_a, sf::RectangleShape &rectangle_b);
        bool checkADIntersection(sf::RectangleShape &rectangle_a, sf::RectangleShape &rectangle_b);
};

// Rectangle Struct for AD:
// If AD gets refactored out we can remove this: 
struct RectangleHelper{
        std::vector<sf::Vector2<float>> p; // Vertexes:
        sf::Vector2<float> pos;			   // Center of Shape:					
    
};