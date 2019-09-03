#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;


class Solution {

//自顶向下
public:
	int integerBreak_1(int n) {
		assert(n >= 2);
		memo = vector<int>(n + 1, -1);
		return breakInteger(n);

	}
private:

	vector<int> memo;
	//将n进行分割（至少分割两部分），可以获得的最大成绩
	int breakInteger(int n)
	{
		if (n == 1)
			return 1;

		if (memo[n] != -1)
			return memo[n];

		int res = -1;
		for (int i = 1; i <= n - 1; ++i)
			//i + (n - i)
			res = max(res, max(i * (n - i), i * breakInteger(n - i)));

		memo[n] = res;
		return res;
	}

//自底向上
public:

	int integerBreak(int n) {
		assert(n >= 2);

		//memo[i]表示将数字i分割（至少分割为两部分）后得到的最大乘积
		vector<int> memo(n + 1, -1);

		memo[1] = 1;
		for (int i = 2; i <= n; ++i)
			//求解memo[i]
			for (int j = 1; j <= i - 1; ++j)
				//j + (i - j)
				memo[i] = max(memo[i], max(j*(i - j), j*memo[i - j]));
							//必须要和自己比，在 前面判断 决定要不要继续分
		return memo[n];


	}
};