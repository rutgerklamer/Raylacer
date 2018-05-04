#ifndef LIGHT_H
#define LIGHT_H

#include "Raylacer/Core/Color.h"
#include "Raylacer/Core/Vector.h"

class Light
{
    public:
        Light();
        ~Light();
        Vector position;
        Color color;
};

#endif //LIGHT_H
