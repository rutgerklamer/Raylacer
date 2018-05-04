#ifndef RAY_H
#define RAY_H

#include <math.h>

#include "Raylacer/Core/Vector.h"
#include "Raylacer/Shapes/Sphere.h"

class Ray
{
    public:
        Ray();
        ~Ray();
        bool intersect_sphere(Sphere* s, float* t);
        Vector start;
        Vector dir;
};

#endif //RAY_H
