#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLIS__(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		//存放每个位置之前数列对应的最长数列长度,并初始为1
		vector<int> t(nums.size(), 1);
		//标记每个位置i： 从j=0到i
		for (int i = 1; i < nums.size(); ++i)
			for (int j = 0; j < i; ++j)//这里要分别判断之前每一个 j
				//判断 nums[i] 是否贡献之前的递增数列
				if (nums[i] > nums[j]) 
					if (t[j] + 1 > t[i])
						t[i] = t[j] + 1;
		int res = 0;
		for (auto a : t)
			if (a > res)
				res = a;
		return res;
	}
	//牛逼 牛逼 牛逼
	int lengthOfLIS(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end())
				res.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return res.size();
	}
};
void main_Longest_Increasing_Subsequence()
{
	vector<int> nums = { 10,9,2,5,3,4 };
	Solution so;
	cout << so.lengthOfLIS(nums) << endl;
	system("pause");
}