#include "physics_intersector.h"

#include <iostream>


//Top level function that determines which determines what function to use:
bool physics_intersector::check_rect_rect_intersection(sf::RectangleShape &A, sf::RectangleShape &B){

    bool retval = false;

    //AABB only accurate if rotations are 0: 
    if(A.getRotation() == 0 && B.getRotation() == 0){  return check_AABB_intersection_rects(A, B); }
    
    //This implements AD and not SAT, but can accomodate any rotation or rect size: 
    else{ return check_SAT_intersection_rects(A, B); }
    
    return false;

}



//Intersection between two rectangles, AABB version:
//Called when two rectangles are passed in and their rotations are identical: 
bool physics_intersector::check_AABB_intersection_rects(sf::RectangleShape &A, sf::RectangleShape &B){

        //Grab A Values:
        sf::Vector2<float> topLeftA = A.getTransform().transformPoint( sf::Vector2<float>(0, 0));
        sf::Vector2<float> topRightA = A.getTransform().transformPoint( sf::Vector2<float>(A.getSize().x, 0));
        sf::Vector2<float> botLeftA = A.getTransform().transformPoint( sf::Vector2<float>(0, A.getSize().y));
        sf::Vector2<float> botRightA = A.getTransform().transformPoint( sf::Vector2<float>(A.getSize().x, A.getSize().y));\
        sf::Vector2<float> centerA =  A.getPosition();

        //Grab B Values:
        sf::Vector2<float> topLeftB = B.getTransform().transformPoint( sf::Vector2<float>(0, 0));
        sf::Vector2<float> topRightB = B.getTransform().transformPoint( sf::Vector2<float>(B.getSize().x,0));
        sf::Vector2<float> botLeftB = B.getTransform().transformPoint( sf::Vector2<float>(0, B.getSize().y));
        sf::Vector2<float> botRightB = B.getTransform().transformPoint( sf::Vector2<float>(B.getSize().x, B.getSize().y));
        sf::Vector2<float> centerB = B.getPosition();


        //Print stats of rectangles here:
        printf("AABB Intersection:\n\n");
        printf("A Statistics:\n");
        printf("Top Left A: %.2f %.2f\n", topLeftA.x, topLeftA.y);
        printf("Top Rite A:  %.2f %.2f\n", topRightA.x, topRightA.y);

        printf("Bot Left A: %.2f %.2f\n", botLeftA.x, botLeftA.y);
        printf("Bot Rite A: %.2f %.2f\n", botRightA.x, botRightA.y);
        printf("A Ori: %.2f %.2f\n", centerA.x, centerA.y);
        printf("A Rot: %.2f\n\n", A.getRotation());


        printf("B Statistics\n");
        printf("Top Left B: %.2f %.2f\n", topLeftB.x, topLeftB.y);
        printf("Top Rite B:  %.2f %.2f\n", topRightB.x, topRightB.y);

        printf("Bot Left B: %.2f %.2f\n", botLeftB.x, botLeftB.y);
        printf("Bot Rite B: %.2f %.2f\n", botRightB.x, botRightB.y);
        printf("B Ori: %.2f %.2f\n", centerB.x, centerB.y);
        printf("B Rot: %.2f\n\n", B.getRotation());

        
        //AABB collision is simple checking: This is described below: 
        //For AABB collision detection to say that there was a collision between two bounding boxes, there is a simple checklist.
        //Is the x-coordinate position of the left edge of Bounding Box 1 less than the x-coordinate position of the right edge of Bounding Box 2?
        if(topLeftA.x < topRightB.x 
        //Is the x-coordinate position of the right edge of Bounding Box 1 greater than the x-coordinate position of the left edge of Bounding Box 2?
        && topRightA.x > topLeftB.x 
        //Is the y-coordinate position of the top edge of Bounding Box 1 less than the y-coordinate position of the bottom edge of Bounding Box 2?
        && topLeftA.y < botLeftB.y 
        //is the y-coordinate position of the bottom edge of Bounding Box 1 greater than the y-coordinate position of the top edge of Bounding Box 2?
        && botLeftA.y > topLeftB.y){

            printf("AABB Collision Detected:");
            return true;

        }

        return false;
}


//Intersection between two rectangles, AD version:
//Called when two rectangles are passed in and their rotations non identical: 
bool physics_intersector::check_SAT_intersection_rects(sf::RectangleShape &A, sf::RectangleShape &B){


    //Grab A Values:
    sf::Vector2<float> topLeftA = A.getTransform().transformPoint( sf::Vector2<float>(0, 0));
    sf::Vector2<float> topRightA = A.getTransform().transformPoint( sf::Vector2<float>(A.getSize().x, 0));
    sf::Vector2<float> botLeftA = A.getTransform().transformPoint( sf::Vector2<float>(0, A.getSize().y));
    sf::Vector2<float> botRightA = A.getTransform().transformPoint( sf::Vector2<float>(A.getSize().x, A.getSize().y));
    sf::Vector2<float> centerA =  A.getPosition();

    //Grab B Values:
    sf::Vector2<float> topLeftB = B.getTransform().transformPoint( sf::Vector2<float>(0, 0));
    sf::Vector2<float> topRightB = B.getTransform().transformPoint( sf::Vector2<float>(B.getSize().x,0));
    sf::Vector2<float> botLeftB = B.getTransform().transformPoint( sf::Vector2<float>(0, B.getSize().y));
    sf::Vector2<float> botRightB = B.getTransform().transformPoint( sf::Vector2<float>(B.getSize().x, B.getSize().y));
    sf::Vector2<float> centerB = B.getPosition();

    //Print out the statistics of the method: 
    printf("AD Intersection:\n\n");
    printf("A Statistics:\n");
    printf("Top Left A: %.2f %.2f\n", topLeftA.x, topLeftA.y);
    printf("Top Rite A:  %.2f %.2f\n", topRightA.x, topRightA.y);

    printf("Bot Left A: %.2f %.2f\n", botLeftA.x, botLeftA.y);
    printf("Bot Rite A: %.2f %.2f\n", botRightA.x, botRightA.y);
    printf("A Ori: %.2f %.2f\n", centerA.x, centerA.y);
    printf("A Rot: %.2f\n\n", A.getRotation());


    printf("B Statistics\n");
    printf("Top Left B: %.2f %.2f\n", topLeftB.x, topLeftB.y);
    printf("Top Rite B:  %.2f %.2f\n", topRightB.x, topRightB.y);

    printf("Bot Left B: %.2f %.2f\n", botLeftB.x, botLeftB.y);
    printf("Bot Rite B: %.2f %.2f\n", botRightB.x, botRightB.y);
    printf("B Ori: %.2f %.2f\n", centerB.x, centerB.y);
    printf("B Rot: %.2f\n\n", B.getRotation());

    //Take all of the data we just collected
    //Store them in the structs provided to us by javidx9
    //Remember, we need to build the rectangle from points, so how they are pushed into the vector matters: 
    polygon r1;
    r1.pos = {centerA.x, centerA.y};
    r1.p.push_back({ topLeftA.x, topLeftA.y });
    r1.p.push_back({ topRightA.x, topRightA.y });
    r1.p.push_back({ botRightA.x, botRightA.y });
    r1.p.push_back({ botLeftA.x, botLeftA.y });


    polygon r2;
    r2.pos = {centerB.x, centerB.y};
    r2.p.push_back({ topLeftB.x, topLeftB.y });
    r2.p.push_back({ topRightB.x, topRightB.y });
    r2.p.push_back({ botRightB.x, botRightB.y });
    r2.p.push_back({ botLeftB.x, botLeftB.y });


    //Struct pointers for AD/SAT: 
    //Determines which shape is currently being checked against the other: 
    //Also makes code cleaner, thanks javidx9 for the tip: 
	polygon *poly1 = &r1;
	polygon *poly2 = &r2;

    

    //Start of the AD theorem: 
    for (int shape = 0; shape < 2; shape++){
			
        //Determines which shape is being tested against the edges:
        if (shape == 1){
			poly1 = &r2;
			poly2 = &r1;
		
        }
			
		//Grabs the center of the shape and an edge: Uses this to test against edges of other:
		for (int p = 0; p < poly1->p.size(); p++){
			vec2d line_r1s = poly1->pos;
			vec2d line_r1e = poly1->p[p];

			//Grabbing edges of other shape: 
			for (int q = 0; q < poly2->p.size(); q++){
				vec2d line_r2s = poly2->p[q];
				vec2d line_r2e = poly2->p[(q + 1) % poly2->p.size()];

				// Standard "off the shelf" line segment intersection
				float h = (line_r2e.x - line_r2s.x) * (line_r1s.y - line_r1e.y) - (line_r1s.x - line_r1e.x) * (line_r2e.y - line_r2s.y);
				float t1 = ((line_r2s.y - line_r2e.y) * (line_r1s.x - line_r2s.x) + (line_r2e.x - line_r2s.x) * (line_r1s.y - line_r2s.y)) / h;
				float t2 = ((line_r1s.y - line_r1e.y) * (line_r1s.x - line_r2s.x) + (line_r1e.x - line_r1s.x) * (line_r1s.y - line_r2s.y)) / h;

                //If intersection, print out and let user know: 
				if (t1 >= 0.0f && t1 < 1.0f && t2 >= 0.0f && t2 < 1.0f){
						printf("Intersection Detected: Check Num: %d, %.2f, %.2f, %.2f\n", shape, h, t1, t2);
                        return true;
				}
				
            }
			    
        }		
    }


    //If we reached this point, there are no AD intersections:
    return false;
}
