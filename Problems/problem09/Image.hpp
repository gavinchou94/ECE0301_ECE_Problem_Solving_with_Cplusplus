#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <string>
#include <cstdint>

#include "bitmap.hpp"

class Image
{
public:
    Image();
    // TODO: size constructors
    Image(int size);
    Image(int w, int h);

    // TODO: copy constructor
    Image(const Image &im);

    // TODO: destructor
    ~Image();

    // TODO: copy assignment
    Image &operator=(Image im);

    int get_width() const;
    int get_height() const;

    RGBPIXEL get_pixel(int index) const;
    void set_pixel(int index, const RGBPIXEL color);

    // BONUS: file read/write
    bool load_from_file(std::string filename);
    bool save_to_file(std::string filename);

private:
    int width;
    int height;
    RGBPIXEL *image_data;
};

// TODO: non-member overloaded addition operator
Image operator+(const Image &im, const RGBPIXEL &val);
Image operator+(const RGBPIXEL &val, const Image &im);

// This will be useful if attempting bonus
// // OPTIONAL for bonus: subtraction operator
// Image operator-(const Image &im, const RGBPIXEL &val);
// Image operator-(const RGBPIXEL &val, const Image &im);

#endif