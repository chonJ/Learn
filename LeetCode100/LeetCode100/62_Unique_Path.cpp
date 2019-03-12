#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePaths_zixie(int m, int n) {
		if (m == 1 && n == 1)
			return 1;
		else if (m == 1)
		{
			return uniquePaths(1, n - 1);
		}
		else if (n == 1)
		{
			return uniquePaths(m - 1, 1);
		}
		else
			return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
	}
	//讲解 进阶三部曲

	// 1
	int uniquePaths_1(int m, int n)
	{
		vector<vector<int>> path(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				path[i][j] = path[i - 1][j] + path[i][j - 1];
		return path[m - 1][n - 1];
	}
	// 2
	int uniquePaths_2(int m, int n)
	{
		if (m > n) return uniquePaths_2(n, m);
		vector<int> pre(m, 1);
		vector<int> cur(m, 1);
		for (int j = 1; j < n; ++j)
		{
			for (int i = 1; i < m; ++i)
				cur[i] = cur[i - 1] + pre[i];
			swap(pre, cur);
		}
		return pre[m - 1];
	}
	// 3
	int uniquePaths(int m, int n)
	{
		if (m > n) return uniquePaths(n, m);
		vector<int> cur(m, 1);
		for (int j = 1; j < n; ++j)
			for (int i = 1; i < m; ++i)
				cur[i] += cur[i - 1];
		return cur[m - 1];
	}
};

void main_Unique_paths()
{
	int m = 51, n = 9;
	Solution so;
	int res = so.uniquePaths(m, n);
	cout << res << endl;
	system("pause");
}