#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> >& board, string word)
	{
		if (board.size() == 0)
			return false;
		m = board.size();
		n = board[0].size();
		for(int x = 0;x < m;++x)
			for (int y = 0; y < n; ++y)
			{
				if (isFound(board,word.c_str(),x,y))
					return true;
			}
		return false;
	}
private:
	int m, n;
	bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
	{
		if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' || board[x][y] != *w)
			return false;
		if (*(w + 1) == '\0')
			return true;
		char t = board[x][y];
		board[x][y] = '\0';
		if (isFound(board, w + 1, x - 1, y) || isFound(board, w + 1, x, y - 1) || isFound(board, w + 1, x + 1, y) || isFound(board, w + 1, x, y + 1))
			return true;
		board[x][y] = t;
		return false;
	}
};

void main_Word_Search()
{
	vector<vector<char> > board = 
	{
		{'A','B','C','E' },
		{'S','F','C','S'},
		{'A','D','E','E' }
	};
	string w = "ABCB";
	Solution so;
	bool res = so.exist(board, w);
	cout << res << endl;

	system("pause");

}