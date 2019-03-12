#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> v;
		subset(res,nums,0,v);
		
		res.push_back(v);
		return res;
	}
	void subset(vector<vector<int>> &res,vector<int>& nums,int begin,vector<int>& v)
	{
		if (begin ==  nums.size())
		{
			if (v.size() != 0)
				res.push_back(v);
			return;
		}
			
				
		v.push_back(nums[begin]);
		subset(res, nums, begin + 1, v);
		v.pop_back();
		subset(res, nums, begin + 1, v);

	}
};

void main_Subsets()
{
	vector<int> nums = { 1,2,3 };
	Solution so;
	vector<vector<int>> res = so.subsets(nums);
	for (auto a : res)
	{
		for (auto b : a)
			cout << b;
		cout << endl;
	}
	system("pause");
}