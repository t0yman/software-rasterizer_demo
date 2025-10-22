#include <cmath>

#include "point2.hpp"
#include "ppm_image.hpp"

int main()
{
    const int width = 400;
    const int height = 400;

    PpmImage ppmImage{width, height};

    // t1: general-case triangle with vertices in asecending y order
    // bottom=red initially, then bottom=white (general-case marker)
    // middle=green initially, then middle=white
    // top=blue 
    ppmImage.DrawFilledTriangle(Point2{50.0, 50.0}, Point2{100.0, 150.0}, Point2{150.0, 250.0}, Color{1.0, 0.0, 0.0});

    // t2: general-case triangle with vertices in descending y order
    // to check if sorting works regardless of input order
    // bottom={250,50}, middle={300,150}, top={350,250}
    ppmImage.DrawFilledTriangle(Point2{350.0, 250.0}, Point2{300.0, 150.0}, Point2{250.0, 50.0}, Color{0.0, 1.0, 0.0});

    // t3: general-case triangle with vertices in random order
    // to check if sorting works regardless of input order
    // bottom={50,280}, middle={100,320}, top={150,360}
    ppmImage.DrawFilledTriangle(Point2{100.0, 320.0}, Point2{150.0, 360.0}, Point2{50.0, 280.0}, Color{0.0, 0.0, 1.0});

    // t4: flat-bottom triangle
    // to check detection of degenerate case
    // bottom=cyan, top=yellow
    ppmImage.DrawFilledTriangle(Point2{250.0, 50.0}, Point2{300.0, 50.0}, Point2{275.0, 150.0}, Color{1.0, 1.0, 0.0});

    // t5: flat-top triangle
    // to check detection of degenerate case
    // bottom=cyan
    ppmImage.DrawFilledTriangle(Point2{275.0, 280.0}, Point2{250.0, 360.0}, Point2{300.0, 360.0}, Color{0.0, 1.0, 1.0});

    // t6: completely flat triangle
    // to check detection of degenerate case
    // middle=magenta
    ppmImage.DrawFilledTriangle(Point2{350.0, 200.0}, Point2{370.0, 200.0}, Point2{360.0, 200.0}, Color{1.0, 0.0, 1.0});

    // t7: flat-bottom triangle
    // to check detection of degenerate case
    // bottom=cyan, top=yellow
    ppmImage.DrawFilledTriangle(Point2{175.0, 150.0}, Point2{150.0, 50.0}, Point2{200.0, 50.0}, Color{1.0, 0.5, 0.0});

    // t8: general-case triangle
    // to test general-case detection for extreme shapes
    ppmImage.DrawFilledTriangle(Point2{370.0, 50.0}, Point2{372.0, 150.0}, Point2{368.0, 250.0}, Color{0.5, 0.0, 0.5});

    ppmImage.Write("output");

    return 0;
}