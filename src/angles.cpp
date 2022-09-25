//
// Created by loona on 25/09/22.
//

#include "angles.h"

float radians(float degrees){
    return (degrees * M_PI) / 180;
}

float degrees(float radians) {
    return (radians * 180) / M_PI;
}