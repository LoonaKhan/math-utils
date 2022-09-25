//
// Created by loona on 25/09/22.
//

#include "angles.h"
#include "iostream"

void radiansTest(){
    // test for all ints
    // and for floats
    for (float i=0; i<=1.1; i+=0.1)
        std::cout << "radians(" << i << "): " << radians(i) << std::endl;
}

void degreesTest(){
    // test for all ints
    // and for floats
    for (float i=0; i<=10; i+=M_PI/3)
        std::cout << "degrees(" << i << "): " << degrees(i) << std::endl;
}

int main() {
    //radiansTest();
    //degreesTest();
}