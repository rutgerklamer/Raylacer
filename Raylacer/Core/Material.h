#ifndef MATERIAL_H
#define MATERIAL_H

#include "Raylacer/Core/Color.h"

class Material
{
    public:
        Material();
        ~Material();
        Color color;
        Color diffuse;
        float reflectivity;

};

#endif //PIXEL_H
