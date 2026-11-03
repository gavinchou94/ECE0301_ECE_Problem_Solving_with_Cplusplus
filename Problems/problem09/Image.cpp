#include "Image.hpp"

#include <stdexcept>

// Provided: empty image.
Image::Image() : width(0), height(0), image_data(nullptr)
{
}

Image::Image(int size) : width(0), height(0), image_data(nullptr)
{
  // TODO
  // Placeholder: the initializer list above only creates an empty image so
  // the starter code runs safely. Replace it with your own initialization.
}

Image::Image(int w, int h) : width(0), height(0), image_data(nullptr)
{
  // TODO
  // Placeholder: the initializer list above only creates an empty image so
  // the starter code runs safely. Replace it with your own initialization.
}

Image::Image(const Image &im) : width(0), height(0), image_data(nullptr)
{
  // TODO: make sure to apply deep copy
  // Placeholder: the initializer list above only creates an empty image so
  // the starter code runs safely. Replace it with your own initialization.
}

Image::~Image()
{
  // TODO
}

Image &Image::operator=(Image im)
{
  // TODO: make sure to apply copy-swap-idiom
  return *this;
}

int Image::get_width() const
{
  return width;
}

int Image::get_height() const
{
  return height;
}

// Add the const and non-const operator[] definitions here.
// Both must reject negative indices and indices >= width * height.

RGBPIXEL Image::get_pixel(int index) const
{
  // TODO: call the const version of operator[].
  return RGBPIXEL();
}

void Image::set_pixel(int index, const RGBPIXEL color)
{
  // TODO: call the non-const version of operator[] to assign color.
}

bool Image::load_from_file(std::string filename)
{
  // BONUS: adopt imported data on success; leave this image unchanged on failure.
  return false;
}

bool Image::save_to_file(std::string filename)
{
  // BONUS: return false for an empty image; otherwise return the export result.
  return false;
}

Image operator+(const Image &im, const RGBPIXEL &val)
{
  // TODO
  return Image();
}

Image operator+(const RGBPIXEL &val, const Image &im)
{
  // TODO
  return Image();
}