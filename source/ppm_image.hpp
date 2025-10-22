#pragma once

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "color.hpp"
#include "point2.hpp"

class PpmImage
{
public:
    PpmImage() = default;
    PpmImage(PpmImage&&) = default;
    PpmImage(const PpmImage&) = default;
    inline PpmImage(int width, int height) : width_{width}, height_{height}, pixelBuffer_{static_cast<std::vector<Color>::size_type>(width_ * height_)} {};

    PpmImage& operator=(PpmImage&&) = default;
    PpmImage& operator=(const PpmImage&) = default;

    ~PpmImage() = default;

    void DrawLine(const Point2& a, const Point2& b);
    void DrawTriangle(const Point2& a, const Point2& b, const Point2& c);
    void DrawFilledTriangle(const Point2& a, const Point2& b, const Point2& c, const Color& color);

    void Write(std::string filename) const;

    inline void SetPixel(int x, int y, const Color& color) { pixelBuffer_[width_ * y + x] = color; };

private:
    const int width_;
    const int height_;

    std::vector<Color> pixelBuffer_;
};