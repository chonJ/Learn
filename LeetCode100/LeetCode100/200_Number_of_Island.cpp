#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		int count = 0;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == '1')
				{
					count++;
					search(grid, row, col, i, j);
				}
			}
		return count;
	}
	void search(vector<vector<char>>& grid, int row, int col, int i, int j)
	{
		if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == '1')
		{
			grid[i][j] = '0';
			search(grid, row, col, i - 1, j);
			search(grid, row, col, i, j - 1);
			search(grid, row, col, i + 1, j);
			search(grid, row, col, i, j + 1);
		}
	}
};

void main_Number_of_Island()
{
	vector<vector<char>> grid = 
	{
		{'1','1','1','0'},
		{'1','0','1','0'},
		{'1','0','0','0'},
		{'0','0','0','0'}
	};
	Solution so;
	cout << so.numIslands(grid) << endl;
	system("pause");
}