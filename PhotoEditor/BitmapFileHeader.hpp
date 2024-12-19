#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(push, 1)                     // Desativa o alinhamento de mem�ria padr�o

namespace Bitmap
{

	struct BitmapFileHeader
	{
		char header[2]{ 'B', 'M' };       // Tipo do arquivo (deve ser "BM")
		uint32_t fileSize;                // Tamanho do arquivo em bytes
		uint32_t reserved{ 0 };           // 32-bits Reservados (valor fixo: 0)
		uint32_t dataOffset;              // Offset para o in�cio dos dados da imagem em bytes
	};

}

#pragma pack(pop)                         // Restaura o alinhamento de mem�ria padr�o

#endif // BITMAPFILEHEADER_H_