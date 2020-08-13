#include "boundingbox.h"
#include "aabbintersector.h"
#include <iostream>

//Intersection between aabb:
//Requires Four Checks:
//Compiler will likely optimize code, set up so I can better debug any conditions if necessary: 
bool aabbIntersector::check_aabb_intersection(aabb_bounding_box *A, aabb_bounding_box *B){

        bool chk_1 = false;
        bool chk_2 = false;
        bool chk_3 = false;
        bool chk_4 = false;

        printf("%.2f %.2f %.2f %.2f\n", A->getX(), A->getY(), A->getWidth(), A->getHeight());
        printf("%.2f %.2f %.2f %.2f\n", B->getX(), B->getY(), B->getWidth(), B->getHeight());

        if(A->getX() < B->getX() + B->getWidth()){ 
            chk_1 = true;
        }

        if(A->getX() + A->getWidth() > B->getWidth()){
            chk_2 = true;
        }


        if(A->getY() < B->getY() + B->getHeight()){
            chk_3 = true;
        }



        if(A->getY() + A->getHeight() > B->getY()){
            chk_4 = true;    
        }


        if(chk_1 && chk_2 && chk_3 && chk_4){
            return true;    
        
        }
        
        return false;
}