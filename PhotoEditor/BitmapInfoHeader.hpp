#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>
using namespace std;
 
#pragma pack(push, 1)                      // Desativa o alinhamento de memória padrão

namespace Bitmap
{

    struct BitmapInfoHeader
    {
        uint32_t headerSize{ 40 };         // Tamanho do cabeçalho em bytes (deve ser 40)
        int32_t  width;                    // Largura da imagem em pixels
        int32_t  height;                   // Altura da imagem em pixels
        uint16_t planes{ 1 };              // Número de planos de cores (deve ser 1)
        uint16_t bitCount{ 24 };           // Profundidade de bits da imagem (1, 4, 8, 16 ou 24)
        uint32_t compression{ 0 };         // Tipo de compressão (0 = sem compressão)
        uint32_t imageSize{ 0 };           // Tamanho dos dados da imagem em bytes (0 se não houver compressão)
        int32_t  xPixelsPerMeter{ 2400 };  // Resolução horizontal da imagem em pixels por metro
        int32_t  yPixelsPerMeter{ 2400 };  // Resolução vertical da imagem em pixels por metro
        uint32_t colorsUsed{ 0 };          // Número de cores na tabela de cores (0 se não houver tabela de cores)
        uint32_t colorsImportant{ 0 };     // Número de cores importantes (0 se todas são importantes)
    };

}

#pragma pack(pop)                          // Restaura o alinhamento de memória padrão

#endif // BITMAPINFOHEADER_H_