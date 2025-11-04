#include "Image.hpp"

#include <stdexcept>

Image::Image() : width(0), height(0), image_data(nullptr) {}

Image::Image(int size)
{
    // TODO
}

Image::Image(int w, int h)
{
    // TODO
}

Image::Image(const Image &im)
{
    // TODO: make sure to apply deep copy
}

Image::~Image()
{
    // TODO
}

Image &Image::operator=(Image im)
{
    // TODO: make sure to apply copy-swap-idiom
}

int Image::get_width() const
{
    return width;
}

int Image::get_height() const
{
    return height;
}

RGBPIXEL Image::get_pixel(int index) const
{
    if (index >= width * height)
    {
        throw std::out_of_range("Pixel index out of range");
    }
    return image_data[index];
}

void Image::set_pixel(int index, const RGBPIXEL color)
{
    if (index >= width * height)
    {
        throw std::out_of_range("Pixel index out of range");
    }
    image_data[index] = color;
}

bool Image::load_from_file(std::string filename)
{
    // BONUS
    return false;
}

bool Image::save_to_file(std::string filename)
{
    // BONUS
    return false;
}

Image operator+(const Image &im, const RGBPIXEL &val)
{
    // TODO
}

Image operator+(const RGBPIXEL &val, const Image &im)
{
    // TODO
}

// This will be useful if attempting bonus
// Image operator-(const Image &im, const RGBPIXEL &val)
// {
//     // OPTIONAL for bonus, to simply return im is wrong
//     return im;
// }

// Image operator-(const RGBPIXEL &val, const Image &im)
// {
//     // OPTIONAL for bonus, to simply return im is wrong
//     return im;
// }