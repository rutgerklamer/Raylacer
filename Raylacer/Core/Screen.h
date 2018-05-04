#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

#include "Raylacer/Core/Color.h"
#include "Raylacer/Core/Pixel.h"

#define WIDTH 1024
#define HEIGHT 720

class Screen
{
    public:
        Screen();
        ~Screen();
        Color background_color;

        Pixel* frame = new Pixel[WIDTH*HEIGHT];

};

#endif //SCREEN_H
