#include<iostream>
#include<string>
using namespace std;
enum Status { zhengque = 0, feifa, kong, yichu };
Status func_Status = zhengque;
class Solution {
public:
	int StrToInt(string str) {
		/*
		if(!str)
		{
			func_Status = kong;
			return 0;
		}
		*/
		int i = 0;
		bool flag = false;
		if (str[i] == '-')
		{
			i++;
			flag = true;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		long long num = strToIntCore(str, i, flag);
		return (int)num;
	}
	int strToIntCore(string str, int i, bool flag)
	{
		long long num = 0;
		int f = flag ? -1 : 1;
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{

				num = num * 10 + f * (str[i] - '0');
				if ((flag && num > 0x7FFFFFFF) || (!flag && num < (signed int)0x80000000))
				{
					func_Status = yichu;
					return 0;
				}
			}
			else
			{
				func_Status = feifa;
				return 0;
			}
			++i;
		}
		return num;
	}
};
void main_StrToInt()
{
	Solution so;
	string a = "123";
	int res = so.StrToInt(a);
	cout << res << endl;
	system("pause");

}