#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;

		vector<int> cur;
		for (vector<vector<int>>::iterator it = grid.begin(); it != grid.end(); ++it)
		{
			if (it == grid.begin())
				cur.push_back((*it)[0]);
			else
				cur.push_back((*it)[0] + cur[cur.size() - 1]);
		}
		//cout << cur[0] << " " << cur[1] << " " << cur[2] << endl;
		if (grid[0].size() == 1)
			return cur[grid.size() - 1];
		for (int j = 1; j < grid[0].size(); ++j)
		{
			for (int i = 0; i < grid.size(); ++i)
			{
				int last = i == 0 ? INT_MAX : cur[i - 1];
				cur[i] = grid[i][j] + (cur[i] < last ? cur[i] : last);
			}
		//cout << cur[0] << " " << cur[1] << " " << cur[2] << endl;
		}
		return cur[grid.size() - 1];
	}
};
void main_MInimum_Path_Sum()
{
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	Solution so;
	cout << so.minPathSum(grid) << endl;
	system("pause");
}