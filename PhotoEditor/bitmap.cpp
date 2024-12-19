#include "Bitmap.hpp"
#include <string>
#include <cstdint>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::system;
using std::string;
using std::uint8_t;

namespace Bitmap
{
	Bitmap::Bitmap(const string& filename, int width, int height) :
		filename(filename), Pixels(new Pixel[width * height]{})
	{
		FileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + width * height * 3;
		FileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		InfoHeader.width = width;
		InfoHeader.height = height;

		file.open(filename, ios::out | ios::binary);

		if (!file) exit(1);
	}

	Bitmap::Bitmap(const string& filename) : filename(filename)
	{
		file.open(filename, ios::in | ios::out | ios::binary);

		if (!file) exit(1);

		file.read(reinterpret_cast<char*>(&FileHeader), sizeof(BitmapFileHeader));
		file.read(reinterpret_cast<char*>(&InfoHeader), sizeof(BitmapInfoHeader));

		InfoHeader.headerSize = 40;

		Pixels.reset(new Pixel[InfoHeader.width * InfoHeader.height]);

		file.seekg(FileHeader.dataOffset, std::ios::beg);

		for (int i = 0; i < (InfoHeader.width * InfoHeader.height); i++)
			file.read(reinterpret_cast<char*>(&Pixels[i]), sizeof(Pixel));

		file.seekg(FileHeader.dataOffset - sizeof(BitmapFileHeader) - sizeof(BitmapInfoHeader), std::ios::beg);
	}

	Bitmap::~Bitmap()
	{
		file.close();

		if (!filename_output.empty())
		{

			filename = filename_output;
			file_output.close();
		}

		string cmd{ "start " };
		cmd += filename;
		system(cmd.c_str());
	}

	void Bitmap::Write()
	{
		file.write(reinterpret_cast<char*>(&FileHeader), sizeof(FileHeader));
		file.write(reinterpret_cast<char*>(&InfoHeader), sizeof(InfoHeader));
		file.write(reinterpret_cast<char*>(Pixels.get()), static_cast<uint64_t>(InfoHeader.width) * InfoHeader.height * 3);
	}

	void Bitmap::Write(const string& filename_output)
	{
		this->filename_output = filename_output;

		file_output.open(filename_output, std::ios::out | std::ios::binary);

		FileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + InfoHeader.width * InfoHeader.height * 3;
		FileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		file_output.write(reinterpret_cast<char*>(&FileHeader), sizeof(FileHeader));
		file_output.write(reinterpret_cast<char*>(&InfoHeader), sizeof(InfoHeader));
		file_output.write(reinterpret_cast<char*>(Pixels.get()), static_cast<uint64_t>(InfoHeader.width) * InfoHeader.height * 3);
	}

	void Bitmap::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{
		Pixel* pixel = Pixels.get();

		pixel += y * InfoHeader.width + x;

		pixel->red = red;
		pixel->green = green;
		pixel->blue = blue;
	}
}