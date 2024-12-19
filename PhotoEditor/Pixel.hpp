#ifndef PIXEL_H_
#define PIXEL_H_

#include <cstdint>
using std::uint8_t;
using std::uint32_t;

#pragma pack(push, 1)                      // Desativa o alinhamento de memória padrão

namespace Bitmap
{
	struct Pixel
	{
		uint8_t red{ 0 };                  // Tom de vermelho ( 0 a 255 )
		uint8_t green{ 0 };                // Tom de verde ( 0 a 255 )
		uint8_t blue{ 0 };                 // Tom de azul ( 0 a 255 )
	};
}

#pragma pack(pop)                          // Restaura o alinhamento de memória padrão

#endif // PIXEL_H_
