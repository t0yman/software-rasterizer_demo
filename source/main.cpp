#include <cmath>

#include "point2.hpp"
#include "ppm_image.hpp"

int main()
{
    const int width = 600;
    const int height = 600;

    PpmImage ppmImage{width, height};

    ppmImage.DrawFilledTriangle(
        Point2{50.0, 50.0},
        Point2{200.0, 50.0},
        Point2{100.0, 400.0},
        Color{1.0, 0.0, 0.0}
    );

    ppmImage.DrawFilledTriangle(
        Point2{450.0, 50.0},
        Point2{300.0, 200.0},
        Point2{400.0, 400.0},
        Color{0.0, 1.0, 0.0}
    );

    ppmImage.DrawFilledTriangle(
        Point2{500.0, 450.0},
        Point2{520.0, 480.0},
        Point2{550.0, 580.0},
        Color{1.0, 1.0, 0.0}
    );

    ppmImage.DrawFilledTriangle(
        Point2{50.0, 450.0},
        Point2{80.0, 550.0},
        Point2{100.0, 580.0},
        Color{1.0, 0.0, 1.0}
    );

    ppmImage.DrawFilledTriangle(
        Point2{350.0, 450.0},
        Point2{420.0, 500.0},
        Point2{380.0, 580.0},
        Color{0.0, 1.0, 1.0}
    );

    ppmImage.Write("output");

    return 0;
}