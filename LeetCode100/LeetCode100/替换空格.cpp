

//指针的运用
#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char* str, int length)
	{
		int countBlank = 0;
		int size = 0;
		for (int i = 0; str[i] != '\0'; ++i)
		{
			if (str[i] == ' ')
				countBlank++;
			size++;
		}
		char* sp1 = str + size;
		char* sp2 = str + size + 2 * countBlank;

		while (sp1 < sp2)
		{
			if (*sp1 == ' ')
			{
				*sp2-- = '0';
				*sp2-- = '2';
				*sp2-- = '%';
			}
			else
				*sp2-- = *sp1--;
		}
	}
};