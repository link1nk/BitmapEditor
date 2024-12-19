#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>
using namespace std;
 
#pragma pack(push, 1)                      // Desativa o alinhamento de mem�ria padr�o

namespace Bitmap
{

    struct BitmapInfoHeader
    {
        uint32_t headerSize{ 40 };         // Tamanho do cabe�alho em bytes (deve ser 40)
        int32_t  width;                    // Largura da imagem em pixels
        int32_t  height;                   // Altura da imagem em pixels
        uint16_t planes{ 1 };              // N�mero de planos de cores (deve ser 1)
        uint16_t bitCount{ 24 };           // Profundidade de bits da imagem (1, 4, 8, 16 ou 24)
        uint32_t compression{ 0 };         // Tipo de compress�o (0 = sem compress�o)
        uint32_t imageSize{ 0 };           // Tamanho dos dados da imagem em bytes (0 se n�o houver compress�o)
        int32_t  xPixelsPerMeter{ 2400 };  // Resolu��o horizontal da imagem em pixels por metro
        int32_t  yPixelsPerMeter{ 2400 };  // Resolu��o vertical da imagem em pixels por metro
        uint32_t colorsUsed{ 0 };          // N�mero de cores na tabela de cores (0 se n�o houver tabela de cores)
        uint32_t colorsImportant{ 0 };     // N�mero de cores importantes (0 se todas s�o importantes)
    };

}

#pragma pack(pop)                          // Restaura o alinhamento de mem�ria padr�o

#endif // BITMAPINFOHEADER_H_