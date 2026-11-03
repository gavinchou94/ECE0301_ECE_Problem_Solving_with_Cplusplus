#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

#include "bitmap.hpp"

// Image class declaration.
class Image
{
public:
  // Provided: empty image.
  Image();

  // Size constructors.
  Image(int size);
  Image(int w, int h);

  // Copy constructor, destructor, and copy assignment.
  Image(const Image &im);
  ~Image();
  Image &operator=(Image im);

  // Provided: dimension accessors.
  int get_width() const;
  int get_height() const;

  // Add the const and non-const operator[] declarations here.

  // Update these wrappers to call operator[].
  RGBPIXEL get_pixel(int index) const;
  void set_pixel(int index, const RGBPIXEL color);

  // Bonus: file loading and saving.
  bool load_from_file(std::string filename);
  bool save_to_file(std::string filename);

private:
  // Provided: private members. Do not change these.
  int width;
  int height;
  RGBPIXEL *image_data;
};

// Non-member addition operators.
Image operator+(const Image &im, const RGBPIXEL &val);
Image operator+(const RGBPIXEL &val, const Image &im);

#endif