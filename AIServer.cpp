
#include <iostream>
#include "ImageDownloader/ImageDownloader.h"
using std::cout;
using std::endl;

int main()
{
	
    ImageDownloader id;
    id.Download("test.png", "https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png");
}


inline void swapInt(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

inline void swapBit(int& a, int& b)
{
	
}