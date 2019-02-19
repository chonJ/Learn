#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> permutes;
		if (nums.size() == 0)
			return res;
		if (nums.size() == 1)//注意一下
		{
			res.push_back(nums);
			return res;
		}

		permute(res, permutes,nums, 0);
		return res;
	}
	void permute(vector<vector<int>>& res, vector<int>& permutes, vector<int>& nums, int begin)
	{
		if (begin == nums.size())
		{
			res.push_back(permutes);
			return;
		}
		for (int i = 0; i <= nums.size()- begin - 1; ++i)
		{
			swap(nums, begin,begin + i);
			permutes.push_back(nums[begin]);
			permute(res, permutes, nums, begin+1);
			swap(nums, begin, begin + i);
			permutes.pop_back();
		}
	}
	void swap(vector<int>& nums,int begin, int k)
	{
		int temp = nums[k];
		nums[k] = nums[begin];
		nums[begin] = temp;
	}
};

void main_Permutations()
{
	vector<int> nums = { 1,2,3};
	Solution so;
	vector<vector<int>> res = so.permute(nums);
	for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it)
	{
		for (vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); ++itt)
			cout << *itt << "	";
		cout << endl;
	}
	system("pause");
}