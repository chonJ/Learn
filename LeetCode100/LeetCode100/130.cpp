#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;

		int m = board.size();
		int n = board[0].size();
		vector<vector<char>> mark(m, vector<char>(n, 'X'));

		int i = 0;
		int j = 0;
		for (; j < n; ++j)
			Mark(board, mark, i, j);
		j--;
		for (i = 1; i < m; ++i)
			Mark(board, mark, i, j);
		i--;
		for (; j >= 0; --j)
			Mark(board, mark, i, j);
		++j;
		for (; i > 0; --i)
			Mark(board, mark, i, j);

		for (int p = 0; p < m; ++p)
			for (int q = 0; q < n; ++q)
				if (board[p][q] != mark[p][q])
					board[p][q] = mark[p][q];

	}
private:
	void Mark(vector<vector<char>>& board, vector<vector<char>>& mark, int i, int j)
	{
		int m = board.size();
		int n = board[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || (mark[i][j] == 'O'))//修改过的 不用在访问

			return;
		if (board[i][j] == 'O')
		{
			mark[i][j] = 'O';
			Mark(board, mark, i - 1, j);
			Mark(board, mark, i, j - 1);
			Mark(board, mark, i + 1, j);
			Mark(board, mark, i, j + 1);
		}
	}
};