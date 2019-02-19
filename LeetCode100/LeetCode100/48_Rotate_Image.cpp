#include<iostream>
#include<vector>
using namespace std;

//矩阵的 顺时针旋转 & 逆时针旋转    都可以由 矩阵的 一次上下换 + 角对称  或者 一次左右换 + 角对称 实现

class Solution {
public:
	void rotate(vector<vector<int>>& m) {
		int n = m.size();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				swap(m[i][j], m[j][i]);

		for (int i = 0; i < n; i++)
			reverse(m[i].begin(), m[i].end());
	}
	//最直接的 最快的方法
	void rotate1(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = i; j < n - 1 - i; ++j)
			{
				int z = matrix[i][j];
				matrix[i][j] = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
				matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = z;
			}
		}
	}
};

void main_Rotate_Image()
{
	vector<vector<int>> m = { {1,2,3},{4,5,6},{7,8,9} };
	Solution so;
	so.rotate1(m);
	for (vector<vector<int>>::iterator it = m.begin(); it != m.end(); ++it)
	{
		for (vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); ++itt)
			cout << *itt << "	";
		cout << endl;
	}
	system("pause");
}