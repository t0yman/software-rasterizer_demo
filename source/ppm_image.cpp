#include "ppm_image.hpp"

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