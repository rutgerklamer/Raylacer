#include "Raylacer/Core/Vector.h"

Vector::Vector()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Vector::sub(Vector* v1, Vector* v2) {
	Vector result;
  result.x = v1->x - v2->x;
  result.y = v1->y - v2->y;
  result.z = v1->z - v2->z;
	return result;
}

float Vector::dot(Vector* v1, Vector* v2) {
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate Vector x Scalar and return resulting Vector*/
Vector Vector::scale(float c, Vector* v1){
        Vector result;
        result.x = v1->x * c;
        result.y = v1->y * c;
        result.z = v1->z * c;
        return result;
}

/* Add two vectors and return the resulting vector */
Vector Vector::add(Vector* v1, Vector* v2){
        Vector result;
        result.x = v1->x + v2->x;
        result.y = v1->y + v2->y;
        result.z = v1->z + v2->z;
        return result;
}
