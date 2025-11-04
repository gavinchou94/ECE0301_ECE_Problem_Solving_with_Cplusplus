#ifndef _BITMAP_HPP
#define _BITMAP_HPP

#include <cstdint>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

/*
    Adapted from “BMP Puzzles”
    http://nifty.stanford.edu/2011/malan-bmp-puzzles/
    by David J. Malan
    used under CC BY-NC-SA 3.0 http://creativecommons.org/licenses/by-nc-sa/3.0/
 */

typedef uint8_t _BYTE;
typedef uint32_t _DWORD;
typedef int32_t _LONG;
typedef uint16_t _WORD;

/*
 * RGBPIXEL
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */

struct RGBPIXEL
{
    _BYTE blue;
    _BYTE green;
    _BYTE red;
} __attribute__((__packed__));

// common colors
const RGBPIXEL BLACK = {0x00, 0x00, 0x00};
const RGBPIXEL WHITE = {0xFF, 0xFF, 0xFF};
const RGBPIXEL BLUE = {0xFF, 0x00, 0x00};
const RGBPIXEL GREEN = {0x00, 0xFF, 0x00};
const RGBPIXEL RED = {0x00, 0x00, 0xFF};

/* Pixel operators */
inline bool operator==(const RGBPIXEL &a, const RGBPIXEL &b)
{
    if (a.blue == b.blue && a.green == b.green && a.red == b.red)
    {
        return true;
    }
    return false;
}

inline bool operator!=(const RGBPIXEL &a, const RGBPIXEL &b)
{
    return !operator==(a, b);
}

static _BYTE normalize(const _WORD &a)
{
    if (a > UINT8_MAX)
    {
        return UINT8_MAX;
    }
    return a;
}

inline RGBPIXEL operator+(const RGBPIXEL &a, const RGBPIXEL &b)
{
    RGBPIXEL result;
    _WORD blue = a.blue + b.blue;
    _WORD green = a.green + b.green;
    _WORD red = a.red + b.red;

    result.blue = normalize(blue);
    result.green = normalize(green);
    result.red = normalize(red);

    return result;
}

inline RGBPIXEL operator-(const RGBPIXEL &a, const RGBPIXEL &b)
{
    RGBPIXEL result;

    result.blue = a.blue > b.blue ? a.blue - b.blue : 0x00;
    result.green = a.green > b.green ? a.green - b.green : 0x00;
    result.red = a.red > b.red ? a.red - b.red : 0x00;

    return result;
}

inline std::ostream &operator<<(std::ostream &os, const RGBPIXEL &p)
{
    os << (int)p.blue << ',' << (int)p.green << ',' << (int)p.red;
    return os;
}

/* Image data with size */
struct RGBIMAGEDATA
{
    RGBPIXEL *data;
    _LONG width;
    _LONG height;
};

/*
 * _BITMAPFILEHEADER
 *
 * The _BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */

struct _BITMAPFILEHEADER
{
    _WORD bfType;
    _DWORD bfSize;
    _WORD bfReserved1;
    _WORD bfReserved2;
    _DWORD bfOffBits;
} __attribute__((__packed__));

/*
 * _BITMAPINFOHEADER
 *
 * The _BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */

struct _BITMAPINFOHEADER
{
    _DWORD biSize;
    _LONG biWidth;
    _LONG biHeight;
    _WORD biPlanes;
    _WORD biBitCount;
    _DWORD biCompression;
    _DWORD biSizeImage;
    _LONG biXPelsPerMeter;
    _LONG biYPelsPerMeter;
    _DWORD biClrUsed;
    _DWORD biClrImportant;
} __attribute__((__packed__));

/* File I/O */
inline RGBIMAGEDATA import_bmp(std::string infile_name)
{
    // open input file
    std::ifstream input(infile_name, std::ios::binary);
    if (input.fail())
    {
        std::cerr << "Failed to open input file" << std::endl;
        RGBIMAGEDATA empty = {nullptr, 0, 0};
        return empty;
    }

    // check input file format
    // read infile's _BITMAPFILEHEADER
    _BITMAPFILEHEADER bf;
    input.read(reinterpret_cast<char *>(&bf), sizeof(_BITMAPFILEHEADER));

    // read infile's _BITMAPINFOHEADER
    _BITMAPINFOHEADER bi;
    input.read(reinterpret_cast<char *>(&bi), sizeof(_BITMAPINFOHEADER));

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        input.close();
        std::cerr << "Unsupported file format." << std::endl;
        RGBIMAGEDATA empty = {nullptr, 0, 0};
        return empty;
    }

    // allocate image data
    _LONG biHeight = std::abs(bi.biHeight);
    RGBPIXEL *data = new RGBPIXEL[bi.biWidth * biHeight];

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBPIXEL)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0; i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // read RGB triple
            RGBPIXEL triple;
            input.read(reinterpret_cast<char *>(&triple), sizeof(RGBPIXEL));

            // assign pixel value to image
            data[i * bi.biWidth + j] = triple;
        }

        // skip over padding, if any
        input.seekg(padding, std::ios_base::cur);
    }
    RGBIMAGEDATA result = {data, bi.biWidth, biHeight};
    return result;
}

inline bool export_bmp(RGBIMAGEDATA im, std::string outfile_name)
{
    // open input file
    std::ofstream output(outfile_name, std::ios::binary);
    if (output.fail())
    {
        std::cerr << "Failed to open output file" << std::endl;
        return false;
    }

    // create and write headers
    _BITMAPFILEHEADER bf = {
        0x4d42, // type (ascii BM)
        486,    // size in bytes
        0,      // reserved1 must be 0
        0,      // reserved2 must be 0
        54      // offset
    };
    output.write(reinterpret_cast<char *>(&bf), sizeof(_BITMAPFILEHEADER));

    _DWORD size = 3 * im.width * im.height;

    _BITMAPINFOHEADER bi = {
        40,         // size of structure
        im.width,   // bitmap width in pixels
        -im.height, // bitmap height, assume top-down (negative)
        1,          // planes - must be 0
        24,         // bits per pixel
        0,          // compression
        size,       // size in bytes
        2834,       // horizontal resolution
        2834,       // vertical resolution
        0,          // color indices used
        0,          // important color indices (0 is all)
    };
    output.write(reinterpret_cast<char *>(&bi), sizeof(_BITMAPINFOHEADER));

    _LONG biHeight = std::abs(bi.biHeight);
    // padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBPIXEL)) % 4) % 4;

    // iterate over scanlines
    for (int i = 0; i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // write RGB triple
            RGBPIXEL triple = im.data[i * bi.biWidth + j];
            output.write(reinterpret_cast<char *>(&triple), sizeof(RGBPIXEL));
        }

        // padding
        char c = 0x00;
        for (int k = 0; k < padding; k++)
        {
            output.write(reinterpret_cast<char *>(&c), sizeof(c));
        }
    }
    return true;
}

#endif