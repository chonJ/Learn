#include<iostream>
#include<vector>
#include "time.h"
using namespace std;

class Solution {
public:
	int majorityElement_____buhao(vector<int>& nums) {//需要一个特殊标志

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != -1)
			{
				int j = i + 1;
				while (j < nums.size() && (nums[i] == nums[j] || nums[j] == -1))
					j++;
				if (j < nums.size())
					nums[j] = -1;
				else
					return nums[i];
			}
		}
		return 0;
	}
	int majorityElement_remember(vector<int>& nums) {
		int count = 0;
		int res;
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			if (count == 0)
			{
				res = nums[i];
				count++;
			}
			else
			{
				count += res == nums[i] ? 1 : -1;
			}

			// return res;
		}
		return res;
	}
	//随机
	int majorityElement(vector<int>& nums) {
		int n = nums.size();
		int res;
		srand((unsigned)time(NULL));
		while (1)
		{
			int i = rand() % n;
			res = nums[i];
			int count = 0;
			for (int j = 0; j < n; ++j)
			{
				if (nums[j] == res)
					count++;
				if (count > n / 2)
					return res;
			}
		}
	}
};

void main_Majority_Element()
{
	vector<int> nums = { 6,5,5 };
	Solution so;
	cout << so.majorityElement(nums) << endl;
	system("pause");
}