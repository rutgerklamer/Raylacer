#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
    public:
        float x,y,z;
        Vector();
        Vector(float x, float y, float z);
        Vector sub(Vector* v1, Vector* v2);
        float dot(Vector* v1, Vector* v2);
        Vector scale(float c, Vector* v1);
        Vector add(Vector* v1, Vector* v2);
};

#endif //VECTOR_H
