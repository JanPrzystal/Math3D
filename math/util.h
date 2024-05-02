#pragma once
#include <cstdlib>
#include "Defs.h"

inline number random_number(){
    return static_cast<number>(rand()) / (RAND_MAX + 1.0);
}

inline double random_number(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_number();
}
