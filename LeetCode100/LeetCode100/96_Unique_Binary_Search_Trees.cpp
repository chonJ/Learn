#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n < 2)
			return 1;
		vector<int> res(n + 1,0);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; ++i)//外循环是 i 作根节点
			for (int j = 1; j <= i; ++j) //内循环是 res[i] = res[0]*res[i-1] + res[1]*res[i-2] + ...+ res[i-1]*res[0]
				res[i] += res[j-1] * res[i - j];
		
		return res[n];
	}
};

void main_96_Unique_Binary_Search_Trees()
{
	int n = 3;
	Solution so;
	cout << so.numTrees(n) << endl;
	system("pause");
}