#include "Raylacer/Core/Color.h"

Color::Color()
{
    r = 0.5f;
    g = 0.5f;
    b = 0.5f;
}

Color::Color(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
