#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
using namespace std;

class Solution {
public:
	//动态规划
	int numSquares_(int n) {
		if (n <= 0)
			return 0;
		vector<int> perfect(n + 1, INT_MAX);
		perfect[0] = 0;
		for(int i = 1;i <= n ;++i)
			for (int j = 1; j * j <= i; ++j)
			{
				perfect[i] = min(perfect[i], perfect[i - j * j] + 1);
			}
		return perfect[n];
	}
private:
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
	// 数学方法
	int numSquares__(int n) {
		
		if (is_square(n))
			return 1;
		while ((n & 3) == 0)
			n >>= 2;
		if ((n & 7) == 7)
			return 4;
		int sqrt_n = (int)(sqrt(n));
		for (int i = 1; i <= sqrt_n; i++)
		{
			if (is_square(n - i * i))
				return 2;
		}
		return 3;
	}
	bool is_square(int a)
	{
		return int(sqrt(a)) * int(sqrt(a)) == a;
	}
	//图 的方法   避免重复！！
	int numSquares(int n) {
		assert(n > 0);

		queue<pair<int, int>> q;
		q.push(make_pair(n, 0));

		vector<bool> visited(n + 1, false);
		visited[n] = true;

		while (!q.empty())
		{
			int num = q.front().first;
			int step = q.front().second;
			q.pop();

			

			for (int i = 1; ; ++i)
			{
				int a = num - i * i;
				if (a < 0)
					break;
				if (a == 0)
					return step + 1;
				if (!visited[a])
				{
					q.push(make_pair(a, step + 1));
					visited[a] = true;
				}
			}
		}
		return 0;
	}
};