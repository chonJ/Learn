#include<iostream>
using namespace std;

void Printnumber(char* number);
void Print1ToNMaxDigitsRescursively(char* number, int length, int index);

void print1ToMaxofNDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToNMaxDigitsRescursively(number, n, 0);
	}
	delete[] number;
}
void Print1ToNMaxDigitsRescursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		Printnumber(number);
		return;
	}
	for (int i = 0; i < length; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToNMaxDigitsRescursively(number, length, index + 1);
	}
}
void Printnumber(char* number)
{
	bool isBeginning0 = true;
	int len = strlen(number);

	for (int i = 0; i < len; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
			printf("%c",number[i]);
	}
	printf("\t");
}