#include "Raylacer/Core/Pixel.h"

Pixel::Pixel()
{
    r = 0.5f;
    g = 0.5f;
    b = 0.5f;
}

Pixel::Pixel(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
