#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix__(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int c = col - 1; c >= 0; --c)
			for (int r = 0; r < row; ++r)
			{
				if (matrix[r][c] == target)
					return true;
				else if (matrix[r][c] < target)
				{
					if (r == row - 1)
						return false;
					else
						continue;
				}
				else
					break;
			}
		return false;
	}
	//优化
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		int row = matrix.size();
		int col = matrix[0].size();

		int i = 0;
		int j = col - 1;
		while (i < row && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				++i;
			else
				--j;
		}
		return false;
	}
};