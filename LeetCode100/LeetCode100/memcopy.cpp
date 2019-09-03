#include<iostream>
using namespace std;

void* memcopy(void* dst, const void* src, size_t size)
{
	if (dst == NULL || src == NULL)
		return NULL;
	void* res = dst;
	char* pdst = (char*)dst;
	char* psrc = (char*)src;
	if (pdst > psrc && pdst < psrc + size)
	{
		pdst = pdst + size - 1;
		psrc = psrc + size - 1;
		while (size--)
			*pdst-- = *psrc--;
	}
	else
	{
		while (size--)
		{
			*pdst++ == *psrc++;
		}
	}
	return res;
}