#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& cadidates, int target)
		{
			sort(cadidates.begin(), cadidates.end());
			vector<vector<int>> res;
			vector<int> conbination;
			combinationSum(cadidates, target, res, conbination, 0);
			return res;
		}
	private:
		void combinationSum(vector<int>cadidates, int target, vector<vector<int>> &res, vector<int> &conbination, int begin)
		{
			if (!target)
			{
				res.push_back(conbination);
				return;
			}
			for (int i = begin; i != cadidates.size() && target >= cadidates[i]; ++i)
			{
				conbination.push_back(cadidates[i]);
				combinationSum(cadidates, target - cadidates[i], res, conbination, i );//可以再用自身但不能再用之前的
				conbination.pop_back();
			}
		}

};

void main_39_combination_Sum()
{
	vector<int> cadidates = { 2,3,5 };
	Solution so;
	vector<vector<int>> res = so.combinationSum(cadidates, 8);
	for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it)
	{
		for (vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); ++itt)
			cout << *itt<<"	" ;
		cout << endl;
	}
	system("pause");
}