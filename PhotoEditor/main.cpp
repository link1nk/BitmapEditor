#include "Bitmap.hpp"
#include <iostream>
using namespace std;

int main(void)
{

	Bitmap::Bitmap bitmap{ "unsort.bmp" };

	// ....

	bitmap.Write("sort.bmp");
}