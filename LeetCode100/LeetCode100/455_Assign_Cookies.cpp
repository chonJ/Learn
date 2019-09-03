#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {

		//从大到小排序  贪心 总是伴随排序
		sort(g.begin(), g.end(), greater<int>());
		sort(s.begin(), s.end(), greater<int>());

		int si = 0, gi = 0;
		int res = 0;
		while (gi < g.size() && si < s.size())
		{
			if (s[si] >= g[gi])
			{
				++res;
				++si;
				++gi;
			}
			else
				++gi;
		}
		return res;
	}
};