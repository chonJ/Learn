#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	int getIndexOf(string s, string m)
	{
		if (s.empty() || m.empty() || m.size() < 1 || s.size() < m.size())
			return -1;
		int i1 = 0, i2 = 0;
		vector<int> next = getNextArray(m);
		while (i1 < s.size() && i2 < m.size())
		{
			if (s[i1] == m[i2])
			{
				++i1;
				++i2;
			}
			else if (next[i2] == -1)
				++i1;
			else
				i2 = next[i2];
		}
		return i2 == m.size() ? i1 - i2 : -1;
	}
private:
	vector<int> getNextArray(string m)
	{
		if (m.size() == 1)
			return { -1 };
		vector<int> next = { -1,0 };
		int i = 2;
		int cn = 0;
		while (i < m.size())
		{
			if (m[cn] == m[i - 1])
			{
				next.push_back(++cn);
				++i;
			}
			else if (cn > 0)
				cn = next[cn];
			else
			{
				next.push_back(0);
				++i;
			}
		}
		return next;
	}
};
void main_KMP()
{
	string s = "ababc";
	string m = "abc";
	Solution so;
	cout << so.getIndexOf(s, m) << endl;
	system("pause");
}