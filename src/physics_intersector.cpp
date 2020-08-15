#include "physics_intersector.h"
#include <iostream>


//Intersection between aabb:
//Requires Four Checks:
//Compiler will likely optimize code, set up so I can better debug any conditions if necessary: 
bool physics_intersector::check_aabb_intersection(sf::RectangleShape &A, sf::RectangleShape &B){

        float ax1 = A.getPosition().x;
        float ay1 = A.getPosition().y;
        float ax2 = A.getLocalBounds().width + ax1;
        float ay2 = A.getLocalBounds().height + ay1;

        float bx1 = B.getPosition().x;
        float by1 = B.getPosition().y;
        float bx2 = B.getLocalBounds().width + bx1;
        float by2 = B.getLocalBounds().height + by1;

    printf("%.2f %.2f %.2f %.2f\n", ax1, ay1, ax2, ay2);
    printf("%.2f %.2f %.2f %.2f\n", bx1, by1, bx2, by2);

        if(ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1) {
            return true;
        }

        
        return false;
}