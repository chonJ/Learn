#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int climbStairs_timeout(int n) {
		if (n < 2)
			return n;
		else if (n == 2)
			return 2;
		else
			return climbStairs(n - 2) + climbStairs(n - 1);
	}
	int climbStairs(int n) {
		vector<int> res = {0,1,2};//长整型
		for (int i = 0; i < n + 1; ++i)
		{
			if (n < 3)
				continue;
			else
				res.push_back(res[res.size() - 1] + res[res.size() - 2]);
		}
			return res[n];
	}
};
void main_climbing_stairs()
{
	Solution so;
	cout << so.climbStairs(44) << endl;
	system("pause");
}