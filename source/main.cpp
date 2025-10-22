#include <cmath>

#include "point2.hpp"
#include "ppm_image.hpp"

int main()
{
    const int width = 200;
    const int height = 200;

    PpmImage ppmImage{width, height};

    ppmImage.DrawTriangle(Point2{100.0, 150.0}, Point2{50.0, 50.0}, Point2{150.0, 50.0});
    ppmImage.DrawTriangle(Point2{10.0, 190.0}, Point2{10.0, 170.0}, Point2{30.0, 180.0});
    ppmImage.DrawTriangle(Point2{20.0, 100.0}, Point2{180.0, 100.0}, Point2{100.0, 110.0});
    ppmImage.DrawTriangle(Point2{100.0, 20.0}, Point2{95.0, 180.0}, Point2{105.0, 180.0});
    ppmImage.DrawTriangle(Point2{100.0, 100.0}, Point2{180.0, 60.0}, Point2{140.0, 170.0});
    ppmImage.DrawTriangle(Point2{60.0, 120.0}, Point2{100.0, 80.0}, Point2{140.0, 120.0});
    ppmImage.DrawTriangle(Point2{100.0, 80.0}, Point2{140.0, 120.0}, Point2{100.0, 160.0});

    ppmImage.Write("output");

    return 0;
}