#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maximalSquare_space_n2(vector<vector<char>>& matrix) {
		
		if (matrix.empty())
			return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		int res = 0;
		vector<vector<int>> dp(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
			{
				if (i > 0 && j > 0)
				{
					if (matrix[i][j] == '1') //装的是char
						dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
				}
				else       //重要
					dp[i][j] = matrix[i][j] - '0';
				if (dp[i][j] > res)
					res = dp[i][j];
			}
		return res * res;
	}
	int maximalSquare(vector<vector<char>>& matrix) {

		if (matrix.empty())
			return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		int res = 0;
		int pre = 0;
		vector<int> dp(row, 0);
		
		for (int j = 0; j < col; ++j)
		{
			for (int i = 0; i < row; ++i)
			{
				int temp = dp[i];
				if (i > 0 && j > 0)
				{
					//if (j == 2 && i == 1)
					//	cout << "pre:	 "<< pre << "dp[i-1]:	 " << dp[i-1] << "dp[i]:	 " << dp[i] << endl;
					if (matrix[i][j] == '1') //装的是char
						dp[i] = min(pre, dp[i - 1], dp[i]) + 1;
					else
						dp[i] = matrix[i][j] - '0';
				}
				else       //重要
					dp[i] = matrix[i][j] - '0';

				if (dp[i] > res)
					res = dp[i];
				
				pre = temp;
			}
			
		}
		return res * res;
	}
private:
	int min(int a, int b, int c)
	{
		if (a > b) a = b;
		if (a > c) a = c;
		return a;
	}


};

void main_Maximal_Square()
{
	vector<vector<char>> matrix = { {'1','1','0','1'},
									{'1','1','0','1'},
									{'1','1','1','1'},
									
								};
	Solution so;
	cout << so.maximalSquare(matrix) << endl;
	system("pause");
}