#include<iostream>
#include<vector>
#include "math.h"
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		if (num < 0)
			return res;
		int e = 0;
		res = {0};
		for (int i = 1; i <= num; ++i)
		{
			if (pow(2, e) == i)
			{
				++e;
				res.push_back(1);
			}
			else
				res.push_back(1 + res[i - pow(2, e - 1)]);
		}
		return res;
	}
	vector<int> countBits_66666(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			res[i] = res[i & i - 1] + 1;
		return res;
		
	}
};
void main_Counting_Bits()
{
	int num = 5;
	Solution so;
	vector<int> res = so.countBits(num);
	for (auto a : res)
		cout << a << endl;
	system("pause");
}