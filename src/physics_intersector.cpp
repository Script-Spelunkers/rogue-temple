#include "physics_intersector.h"
#include <iostream>

//Top level function that determines which determines what function to use:
bool PhysicsIntersector::checkRectangleIntersection(sf::RectangleShape &rectangle_a, sf::RectangleShape &rectangle_b){

    //AABB only accurate if rotations are 0: 
    if(rectangle_a.getRotation() == 0 && rectangle_b.getRotation() == 0){  return checkAABBIntersection(rectangle_a, rectangle_b); }

    //Rotations are not 0, so return AD:      
    return checkADIntersection(rectangle_a, rectangle_b);

}

//Intersection between two rectangles, AABB version:
//Called when two rectangles are passed in and their rotations are identical: 
bool PhysicsIntersector::checkAABBIntersection(sf::RectangleShape &rectangle_a, sf::RectangleShape &rectangle_b){

        //Grab A Values:
        sf::Vector2<float> top_left_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(0, 0));
        sf::Vector2<float> top_right_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(rectangle_a.getSize().x, 0));
        sf::Vector2<float> bot_left_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(0, rectangle_a.getSize().y));
        sf::Vector2<float> bot_right_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(rectangle_a.getSize().x, rectangle_a.getSize().y));\
        sf::Vector2<float> center_a =  rectangle_a.getPosition();

        //Grab B Values:
        sf::Vector2<float> top_left_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(0, 0));
        sf::Vector2<float> top_right_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(rectangle_b.getSize().x,0));
        sf::Vector2<float> bot_left_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(0, rectangle_b.getSize().y));
        sf::Vector2<float> bot_right_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(rectangle_b.getSize().x, rectangle_b.getSize().y));
        sf::Vector2<float> center_b = rectangle_b.getPosition();


        //Print stats of rectangles here:
        printf("AABB Intersection:\n\n");
        printf("A Statistics:\n");
        printf("Top Left A: %.2f %.2f\n", top_left_a.x, top_left_a.y);
        printf("Top Rite A:  %.2f %.2f\n", top_right_a.x, top_right_a.y);

        printf("Bot Left A: %.2f %.2f\n", bot_left_a.x, bot_left_a.y);
        printf("Bot Rite A: %.2f %.2f\n", bot_right_a.x, bot_right_a.y);
        printf("A Ori: %.2f %.2f\n", center_a.x, center_a.y);
        printf("A Rot: %.2f\n\n", rectangle_a.getRotation());


        printf("B Statistics\n");
        printf("Top Left B: %.2f %.2f\n", top_left_b.x, top_left_b.y);
        printf("Top Rite B:  %.2f %.2f\n", top_right_b.x, top_right_b.y);

        printf("Bot Left B: %.2f %.2f\n", bot_left_b.x, bot_left_b.y);
        printf("Bot Rite B: %.2f %.2f\n", bot_right_b.x, bot_right_b.y);
        printf("B Ori: %.2f %.2f\n", center_b.x, center_b.y);
        printf("B Rot: %.2f\n\n", rectangle_b.getRotation());

        
        //AABB collision is simple checking: This is described below: 
        //For AABB collision detection to say that there was a collision between two bounding boxes, there is a simple checklist.
        //Is the x-coordinate position of the left edge of Bounding Box 1 less than the x-coordinate position of the right edge of Bounding Box 2?
        if(top_left_a.x < top_right_b.x 
        //Is the x-coordinate position of the right edge of Bounding Box 1 greater than the x-coordinate position of the left edge of Bounding Box 2?
        && top_right_a.x > top_left_b.x 
        //Is the y-coordinate position of the top edge of Bounding Box 1 less than the y-coordinate position of the bottom edge of Bounding Box 2?
        && top_left_a.y < bot_left_b.y 
        //is the y-coordinate position of the bottom edge of Bounding Box 1 greater than the y-coordinate position of the top edge of Bounding Box 2?
        && bot_left_a.y > top_left_b.y){

            printf("AABB Collision Detected:");
            return true;

        }

        //No collision detected, return false:
        return false;
}

//Intersection between two rectangles, AD version:
//Called when two rectangles are passed in and their rotations non identical: 
bool PhysicsIntersector::checkADIntersection(sf::RectangleShape &rectangle_a, sf::RectangleShape &rectangle_b){

    //Grab A Values:
    sf::Vector2<float> top_left_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(0, 0));
    sf::Vector2<float> top_right_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(rectangle_a.getSize().x, 0));
    sf::Vector2<float> bot_left_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(0, rectangle_a.getSize().y));
    sf::Vector2<float> bot_right_a = rectangle_a.getTransform().transformPoint( sf::Vector2<float>(rectangle_a.getSize().x, rectangle_a.getSize().y));\
    sf::Vector2<float> center_a =  rectangle_a.getPosition();

    //Grab B Values:
    sf::Vector2<float> top_left_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(0, 0));
    sf::Vector2<float> top_right_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(rectangle_b.getSize().x,0));
    sf::Vector2<float> bot_left_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(0, rectangle_b.getSize().y));
    sf::Vector2<float> bot_right_b = rectangle_b.getTransform().transformPoint( sf::Vector2<float>(rectangle_b.getSize().x, rectangle_b.getSize().y));
    sf::Vector2<float> center_b = rectangle_b.getPosition();

    //Print out the statistics of the method: 
    printf("AD Intersection:\n\n");
    printf("A Statistics:\n");
    printf("Top Left A: %.2f %.2f\n", top_left_a.x, top_left_a.y);
    printf("Top Rite A:  %.2f %.2f\n", top_right_a.x, top_right_a.y);

    printf("Bot Left A: %.2f %.2f\n", bot_left_a.x, bot_left_a.y);
    printf("Bot Rite A: %.2f %.2f\n", bot_right_a.x, bot_right_a.y);
    printf("A Ori: %.2f %.2f\n", center_a.x, center_a.y);
    printf("A Rot: %.2f\n\n", rectangle_a.getRotation());


    printf("B Statistics\n");
    printf("Top Left B: %.2f %.2f\n", top_left_b.x, top_left_b.y);
    printf("Top Rite B:  %.2f %.2f\n", top_right_b.x, top_right_b.y);

    printf("Bot Left B: %.2f %.2f\n", bot_left_b.x, bot_left_b.y);
    printf("Bot Rite B: %.2f %.2f\n", bot_right_b.x, bot_right_b.y);
    printf("B Ori: %.2f %.2f\n", center_b.x, center_b.y);
    printf("B Rot: %.2f\n\n", rectangle_b.getRotation());

    // Plan of attack is as follows:
    // Create two structs that represent our SFML rectangles but are easier to manipulate for looping purposes:
    // Create two pointers to these structs, which will be used to test the AD algo:
    // Run the AD algo by javidx9:
    // Return results: 

    RectangleHelper rectangle_helper_a;
    rectangle_helper_a.pos = {center_a.x, center_a.y};
    rectangle_helper_a.p.push_back({ top_left_a.x, top_left_a.y });
    rectangle_helper_a.p.push_back({ top_right_a.x, top_right_a.y });
    rectangle_helper_a.p.push_back({ bot_right_a.x, bot_right_a.y });
    rectangle_helper_a.p.push_back({ bot_left_a.x, bot_left_a.y });

    RectangleHelper rectangle_helper_b;
    rectangle_helper_b.pos = {center_b.x, center_b.y};
    rectangle_helper_b.p.push_back({ top_left_b.x, top_left_b.y });
    rectangle_helper_b.p.push_back({ top_right_b.x, top_right_b.y });
    rectangle_helper_b.p.push_back({ bot_right_b.x, bot_right_b.y });
    rectangle_helper_b.p.push_back({ bot_left_b.x, bot_left_b.y });

    //Struct pointers for AD: 
    //Determines which shape is currently being checked against the other: 
	 RectangleHelper *rectangle_helper_ptr_a = &rectangle_helper_a;
	 RectangleHelper *rectangle_helper_ptr_b = &rectangle_helper_b;

    // Start of the AD theorem: 
    // Thanks to javidx9 for describing the algo in depth: 
    for (int shape = 0; shape < 2; shape++){
			
        //Determines which shape is being tested against the edges:
        //Ptrs get swapped to test inverse.
        if (shape == 1){
			rectangle_helper_ptr_a = &rectangle_helper_b;
			rectangle_helper_ptr_b = &rectangle_helper_a;
		
        }
			
		//Grabs the center of the shape and an edge: Uses this to create a line to  test against the edge line of other:
		for (int p = 0; p < rectangle_helper_ptr_a->p.size(); p++){
	        
            sf::Vector2<float> start_of_line_a = rectangle_helper_ptr_a->pos;
			sf::Vector2<float> end_of_line_a = rectangle_helper_ptr_a->p[p];

			//Grabbing edges of other shape: 
			for (int q = 0; q < rectangle_helper_ptr_b->p.size(); q++){
				sf::Vector2<float> start_of_line_b = rectangle_helper_ptr_b->p[q];
				sf::Vector2<float> end_of_line_b = rectangle_helper_ptr_b->p[(q + 1) % rectangle_helper_ptr_b->p.size()];

				// Line Intersection Algo described by javidx9 in other documents: 
				float h = (end_of_line_b.x - start_of_line_b.x) * (start_of_line_a.y - end_of_line_a.y) - (start_of_line_a.x - end_of_line_a.x) * (end_of_line_b.y - start_of_line_b.y);
				float t1 = ((start_of_line_b.y - end_of_line_b.y) * (start_of_line_a.x - start_of_line_b.x) + (end_of_line_b.x - start_of_line_b.x) * (start_of_line_a.y - start_of_line_b.y)) / h;
				float t2 = ((start_of_line_a.y - end_of_line_a.y) * (start_of_line_a.x - start_of_line_b.x) + (end_of_line_a.x - start_of_line_a.x) * (start_of_line_a.y - start_of_line_b.y)) / h;

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