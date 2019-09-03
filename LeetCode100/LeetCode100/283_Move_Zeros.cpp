#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes__(vector<int>& nums) {

		int len = nums.size();
		if (len < 2)
			return;
		int p0 = 0;
		int p1 = 0;
		for (; p0 < len; ++p0)
		{
			if (nums[p0] == 0)
			{
				if (p1 < p0)
					p1 = p0;
				while (p1 < len && nums[p1] == 0)
					++p1;
				if (p1 == len)
					return;
				else
				{
					nums[p0] = nums[p1];
					nums[p1] = 0;
				}
			}
		}

	}

	//高效
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len < 2)
			return;
		int index = 0;
		for (auto a : nums)
		{
			if (a != 0)
				nums[index++] = a;
		}
		while (index < len)
			nums[index++] = 0;

	}
};
void main_Move_Zeros()
{
	vector<int> nums = { 1,0 };
	Solution so;
	so.moveZeroes(nums);
	for (auto a : nums)
		cout << a << endl;
	system("pause");
}