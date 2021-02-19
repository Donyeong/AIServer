#include <string.h>
namespace StringUtil
{
	bool copyStr(const char * src, char * buf, unsigned int index, unsigned int size)
	{
		if(src == nullptr)
		{
			return false;
		}

		if(buf == nullptr)
		{
			return false;
		}

		memcpy(buf, src + index, size);

		return true;
	}

	int getCharIndex(const char* str, char c, int index, int maxLength = 0)
	{
		if(str == nullptr)
		{
			return -1;
		}
		for	(int i = 0; i < maxLength || maxLength == 0;i++)
		{
			if(str[i + index] == c) return i + index;
		}
		return -1;
	}
}