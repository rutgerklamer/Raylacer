#ifndef EXPORT_H
#define EXPORT_H

#include <fstream>
#include <sstream>

#include "Raylacer/Core/Pixel.h"

namespace Export
{
        void savebmp(const char* filename, int w, int h, int dpi, Pixel* data);
};

#endif //EXPORT_H
