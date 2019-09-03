#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

//记忆化搜索
class Knapsack01_1 {
private:
	vector<vector<int>> memo;

	//用[0...index]的物品，填充容积为c的背包的最大价值
	int bestValue(const vector<int>& w, const vector<int> v, int index, int c)
	{
		if (index < 0 || c <= 0)
			return 0;

		if (memo[index][c] != -1)
			return memo[index][c];
		//情况一
		int res = bestValue(w, v, index - 1, c);
		//情况二
		if (c >= w[index])
			res = max(res,v[index] + bestValue(w, v, index - 1, c - w[index]));

		memo[index][c] = res;
		return res;

	}
public:
	int knapsack01(const vector<int>& w, const vector<int>& v, int C)
	{
		int n = w.size();
		memo = vector<vector<int>>(n, vector<int>(C + 1, -1));
		return bestValue(w, v, n - 1, C);
	}
};
//动态规划
class Knapsack01_2 {
public:
	int knapasck01_1(const vector<int>& w, const vector<int>&v, int C)
	{
		assert(w.size() == v.size());

		int n = w.size();
		if (n == 0)
			return 0;

		vector<vector<int>> memo(n, vector<int>(C + 1, -1));
		for (int j = 0; j <= C; j++)
			memo[0][j] = j >= w[0] ? v[0] : 0;

		for(int i = 0;i < n;++i)
			for (int j = 1; j <= C; ++j)
			{
				memo[i][j] = memo[i - 1][j];
				if (j >= w[i])
					memo[i][j] = max(memo[i][j], v[i] + memo[i - 1][j - w[i]]);
			}
		return memo[n - 1][C];
	}
	//动态规划的空间优化
	int knapasck01_2(const vector<int>& w, const vector<int>&v, int C)
	{
		assert(w.size() == v.size());

		int n = w.size();
		if (n == 0)
			return 0;

		vector<vector<int>> memo(2, vector<int>(C + 1, -1));
		for (int j = 0; j <= C; j++)
			memo[0][j] = j >= w[0] ? v[0] : 0;

		for (int i = 0; i < n; ++i)
			for (int j = 1; j <= C; ++j)
			{
				memo[i%2][j] = memo[(i - 1)%2][j];
				if (j >= w[i])
					memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i - 1)%2][j - w[i]]);
			}
		return memo[(n - 1)%2][C];
	}
	//动态规划的空间优_--------优化
	int knapasck01_3(const vector<int>& w, const vector<int>&v, int C)
	{
		assert(w.size() == v.size());

		int n = w.size();
		if (n == 0)
			return 0;

		vector<int> memo(C + 1, -1);
		for (int j = 0; j <= C; j++)
			memo[j] = j >= w[0] ? v[0] : 0;

		for (int i = 0; i < n; ++i)
			for (int j = C; j >= w[i]; ++j)
			{
				
					memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
			}
		return memo[C];
	}
};