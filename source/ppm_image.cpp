#include "ppm_image.hpp"

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