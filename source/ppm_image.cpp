#include "ppm_image.hpp"

#include <array>
#include <algorithm>

void PpmImage::DrawLine(const Point2& a, const Point2& b)
{
    const double dx = b.x - a.x;  // the change in x direction (measured in number of pixels)
    const double dy = b.y - a.y;  // the change in y direction (measured in number of pixels)

    // absolute value of maximum change in direction (measured in pixels)
    const double absoluteDelta = (std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy));

    const double xStepValue = dx / absoluteDelta;
    const double yStepValue = dy / absoluteDelta;

    double x = a.x;
    double y = a.y;
    // absoluteDelta represents the total number of pixels to be modified
    // for each individual pixel to be modified, set the color to red
    for (int i = 0; i <= absoluteDelta; ++i)
    {
        SetPixel(static_cast<int>(x), static_cast<int>(y), Color{1.0, 0.0, 0.0});

        x += xStepValue;
        y += yStepValue;
    }
}

void PpmImage::DrawTriangle(const Point2& a, const Point2& b, const Point2& c)
{
    DrawLine(a, b);
    DrawLine(b, c);
    DrawLine(c, a);
}

void PpmImage::DrawFilledTriangle(const Point2& a, const Point2& b, const Point2& c, const Color& color)
{
    if (a.y == b.y && a.y == c.y)  // degenerate case: all three vertices have same y coordinate, the triangle is completely flat
    {
        // detected completely flat triangle, draw a magenta pixel at the first vertex to indicate detection
        SetPixel(static_cast<int>(a.x), static_cast<int>(a.y), Color{1.0, 0.0, 1.0});

        return;
    }

    std::array<Point2, 3> pointList{a, b, c};

    // mark vertices to verify sorting: bottom=red, middle=green, top=blue
    SetPixel(static_cast<int>(pointList[0].x), static_cast<int>(pointList[0].y), Color{1.0, 0.0, 0.0});
    SetPixel(static_cast<int>(pointList[1].x), static_cast<int>(pointList[1].y), Color{0.0, 1.0, 0.0});
    SetPixel(static_cast<int>(pointList[2].x), static_cast<int>(pointList[2].y), Color{0.0, 0.0, 1.0});

    std::sort(pointList.begin(), pointList.end(), [](const Point2& a, const Point2& b) -> bool { return (a.y <= b.y); });

    if (pointList[0].y == pointList[1].y)  // if bottomPoint.y == middlePoint.y, then you have a flat-bottom triangle
    {
        const Point2 bottomLeft = (pointList[0].x <= pointList[1].x ? pointList[0] : pointList[1]);
        const Point2 bottomRight = (pointList[0].x <= pointList[1].x ? pointList[1] : pointList[0]);
        const Point2 top = pointList[2];

        DrawFilledFlatBottomTriangle(bottomLeft, bottomRight, top, color);
    }
    else if (pointList[1].y == pointList[2].y)  // else if middlePoint.y == topPoint.y, then you have a flat-top triangle
    {
        const Point2 topLeft = (pointList[1].x <= pointList[2].x ? pointList[1] : pointList[2]);
        const Point2 topRight = (pointList[1].x <= pointList[2].x ? pointList[2] : pointList[1]);
        const Point2 bottom = pointList[0];

        DrawFilledFlatTopTriangle(topLeft, topRight, bottom, color);
    }
    else // otherwise all three vertices have different y coordinates, so split the triangle into two parts
    {
        // detected general-case triangle, mark middle vertex white to indicate detection
        SetPixel(static_cast<int>(pointList[1].x), static_cast<int>(pointList[1].y), Color{1.0, 1.0, 1.0});
    }
}

void PpmImage::DrawFilledFlatBottomTriangle(const Point2& bottomLeft, const Point2& bottomRight, const Point2& top, const Color& color)
{
    const double leftEdgeSlope = (top.x - bottomLeft.x) / (top.y - bottomLeft.y);  // left edge extends from bottomLeft to top
    const double rightEdgeSlop = (top.x - bottomRight.x) / (top.y - bottomRight.y);  // right edge extends from bottomRight to top
 
    double currentLeftXPosition = bottomLeft.x;
    double currentRightXPosition = bottomRight.x;

    for (int y = static_cast<int>(bottomLeft.y); y <= static_cast<int>(top.y); ++y)
    {
        for (int x = static_cast<int>(currentLeftXPosition); x <= static_cast<int>(currentRightXPosition); ++x)
        {
            SetPixel(x, y, color);
        }

        currentLeftXPosition += leftEdgeSlope;
        currentRightXPosition += rightEdgeSlop;
    }
}

void PpmImage::DrawFilledFlatTopTriangle(const Point2& topLeft, const Point2& topRight, const Point2& bottom, const Color& color)
{
    const double leftEdgeSlope = (bottom.x - topLeft.x) / (bottom.y - topLeft.y);  // left edge extends from topLeft to bottom
    const double rightEdgeSlope = (bottom.x - topRight.x) / (bottom.y - topRight.y);  // right edge extends from topRight to bottom

    double currentLeftXPosition = topLeft.x;
    double currentRightXPosition = topRight.x;

    for (int y = static_cast<int>(topLeft.y); y >= static_cast<int>(bottom.y); --y)
    {
        for (int x = static_cast<int>(currentLeftXPosition); x <= static_cast<int>(currentRightXPosition); ++x)
        {
            SetPixel(x, y, color);
        }

        currentLeftXPosition -= leftEdgeSlope;
        currentRightXPosition -= rightEdgeSlope;
    }
}

void PpmImage::Write(std::string filename) const
{
    std::ofstream imageFile{filename.append(".ppm")};
    if (imageFile.is_open() == false)
    {
        throw std::runtime_error{"Failed to open image file."};
    }

    imageFile << "P3\n" << width_ << " " << height_ << "\n255\n";

    for (int y = height_ - 1; y >= 0; --y)
    {
        for (int x = 0; x < width_; ++x)
        {
            const Color currentPixel = pixelBuffer_[width_ * y + x];

            const int r = static_cast<int>(255.999 * currentPixel.x);
            const int g = static_cast<int>(255.999 * currentPixel.y);
            const int b = static_cast<int>(255.999 * currentPixel.z);

            imageFile << r << " " << g << " " << b << "\n";
        }
    }

    imageFile.close();
}