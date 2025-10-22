#include <cmath>

#include "point2.hpp"
#include "ppm_image.hpp"

int main()
{
    const int width = 500;
    const int height = 500;

    PpmImage ppmImage{width, height};

    ppmImage.DrawFilledTriangle(
        Point2{50.0, 50.0},   // bottom left
        Point2{200.0, 50.0},  // bottom right  
        Point2{125.0, 200.0}, // top
        Color{1.0, 0.0, 0.0}  // bright red
    );

    ppmImage.DrawFilledTriangle(
        Point2{375.0, 50.0},  // bottom
        Point2{300.0, 200.0}, // top left
        Point2{450.0, 200.0}, // top right
        Color{0.0, 0.0, 1.0}  // bright blue
    );

    ppmImage.DrawFilledTriangle(
        Point2{50.0, 300.0},   // bottom left
        Point2{200.0, 300.0},  // bottom right
        Point2{125.0, 450.0},  // top
        Color{0.0, 1.0, 0.0}   // bright green
    );

    ppmImage.DrawFilledTriangle(
        Point2{375.0, 300.0},  // bottom
        Point2{300.0, 450.0},  // top left
        Point2{450.0, 450.0},  // top right
        Color{1.0, 1.0, 0.0}   // bright yellow
    );

    ppmImage.DrawFilledTriangle(
        Point2{50.0, 240.0},   // bottom left
        Point2{450.0, 240.0},  // bottom right
        Point2{250.0, 280.0},  // top
        Color{0.0, 1.0, 1.0}   // cyan
    );

    ppmImage.Write("output");

    return 0;
}