#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int max = 1;
		int cur = 1;
		for (int i = 1;i < nums.size();++i)
		{
			if (nums[i - 1] < nums[i])
				cur++;
			else
				cur = 1;
			if (cur > max)
				max = cur;
		}
		return max;
	}
};