#ifndef BITMAP_H_
#define BITMAP_H_

#include "Bitmap.hpp"
#include "BitmapFileHeader.hpp"
#include "BitmapInfoHeader.hpp"
#include "Pixel.hpp"
#include <cstdint>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
using std::uint32_t;
using std::cout;
using std::string;
using std::unique_ptr;
using std::fstream;

namespace Bitmap
{
    class Bitmap
    {
    private:
        string filename;
        string filename_output;

        BitmapFileHeader FileHeader;
        BitmapInfoHeader InfoHeader;

        fstream file;
        fstream file_output;

        unique_ptr<Pixel[]> Pixels;

        struct PixelLocation
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
        };

    public:
        Bitmap(const string& filename, int width, int height);
        Bitmap(const string& filename);
        virtual ~Bitmap();

        void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        void Write();
        void Write(const string& filename_output);
    };
}

#endif // BITMAP_H_