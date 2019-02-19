#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> res;
		addingpar(res, "", n, 0);
		return res;
	}
	void addingpar(vector<string> &v, string str, int n, int m)
	{
		if (n == 0 && m == 0)
		{
			v.push_back(str);
			return ;
		}
		if (m > 0)
			addingpar(v, str + ')', n, m - 1);
		if (n > 0)
			addingpar(v, str + '(', n - 1, m + 1);
	}
};

void main_Generate_Parentheses()
{
	Solution so;
	vector<string> res = so.generateParenthesis(3);
	for (vector<string>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << endl;
	system("pause");
}