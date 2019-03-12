#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> help;
		if (nums.size() == 0)
			return 0;
		int res = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			help.push_back(nums[i]);
			help[i] = i > 0 && help[i - 1] + help[i] > help[i] ? help[i - 1] + help[i] : help[i];
			if (help[i] > res)
				res = help[i];
		}
		return res;
	}
};

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> help;
		if (nums.size() == 0)
			return 0;
		int res = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			help.push_back(nums[i]);
			help[i] = i > 0 && help[i - 1] + help[i] > help[i] ? help[i - 1] + help[i] : help[i];
			if (help[i] > res)
				res = help[i];
		}
		return res;
	}
};
void main_53_Maximum_Subarry()
{
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	Solution so;
	cout << so.maxSubArray(nums) << endl;
	system("pause");
}