#include "ppm_image.hpp"

int main()
{
    const int width = 200;
    const int height = 200;

    PpmImage ppmImage{width, height};
    ppmImage.SetPixel(50, 50, Color{0.0, 0.0, 1.0});
    ppmImage.SetPixel(150, 50, Color{1.0, 0.0, 1.0});
    ppmImage.SetPixel(50, 150, Color{1.0, 1.0, 0.0});
    ppmImage.SetPixel(150, 150, Color{1.0, 0.0, 0.0});
    ppmImage.Write("output");
}