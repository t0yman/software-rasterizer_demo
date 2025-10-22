#include <cmath>

#include "point2.hpp"
#include "ppm_image.hpp"

int main()
{
    const int width = 200;
    const int height = 200;

    PpmImage ppmImage{width, height};

    ppmImage.DrawLine(Point2{0.0, 0.0}, Point2{static_cast<double>(width - 1), static_cast<double>(height - 1)});
    ppmImage.DrawLine(Point2{0.0, static_cast<double>(height - 1)}, Point2{static_cast<double>(width - 1), 0.0});
    ppmImage.DrawLine(Point2{0.0, static_cast<double>(height / 2)}, Point2{static_cast<double>(width - 1), static_cast<double>(height / 2)});
    ppmImage.DrawLine(Point2{static_cast<double>(width / 2), static_cast<double>(height - 1)}, Point2{static_cast<double>(width / 2), static_cast<double>(0.0)});

    ppmImage.Write("output");

    return 0;
}