#include <cmath>

#include "point2.hpp"
#include "ppm_image.hpp"

int main()
{
    const int width = 800;
    const int height = 800;

    PpmImage ppmImage{width, height};

    ppmImage.DrawFilledTriangle(
        Point2{100.0, 100.0},
        Point2{700.0, 150.0},
        Point2{400.0, 650.0},
        Color{0.8, 0.1, 0.1}
    );

    ppmImage.DrawFilledTriangle(
        Point2{150.0, 200.0},
        Point2{350.0, 180.0},
        Point2{250.0, 500.0},
        Color{0.1, 0.3, 0.8}
    );

    ppmImage.DrawFilledTriangle(
        Point2{500.0, 250.0},
        Point2{650.0, 280.0},
        Point2{580.0, 550.0},
        Color{0.2, 0.7, 0.2}
    );

    ppmImage.DrawFilledTriangle(
        Point2{200.0, 500.0},
        Point2{350.0, 520.0},
        Point2{275.0, 700.0},
        Color{0.9, 0.9, 0.1}
    );

    ppmImage.DrawFilledTriangle(
        Point2{450.0, 400.0},
        Point2{600.0, 450.0},
        Point2{520.0, 650.0},
        Color{0.7, 0.2, 0.7}
    );

    ppmImage.DrawFilledTriangle(
        Point2{600.0, 100.0},
        Point2{750.0, 150.0},
        Point2{680.0, 350.0},
        Color{0.2, 0.8, 0.8}
    );

    ppmImage.DrawFilledTriangle(
        Point2{50.0, 600.0},
        Point2{200.0, 650.0},
        Point2{120.0, 750.0},
        Color{0.9, 0.5, 0.1}
    );

    ppmImage.Write("output");

    return 0;
}