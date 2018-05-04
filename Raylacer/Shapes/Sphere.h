#ifndef SPHERE_H
#define SPHERE_H

#include "Raylacer/Core/Material.h"
#include "Raylacer/Core/Vector.h"

class Sphere
{
  public:
    Sphere();
    ~Sphere();
    Vector position;
    Material material;
    float  radius;
};

#endif //SPHERE_H
