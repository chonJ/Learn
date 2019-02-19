#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	
	bool canJump(vector<int>& nums) {
		if (nums.size() == 0)
			return false;
		if (nums.size() == 1)
			return true;
		return canJump(nums, nums.size() - 1);
	}
	//时间溢出
	bool canJump1(vector<int>& nums, int target )
	{
		if (target == 0)
		{
			if (nums[0] >= 1)
				return true;
			else
				return false;
		}
		bool flag = false;
		for (int i = 1; !flag && target >= i; i++)
		{
			flag = nums[target - i] >= i && canJump(nums, target - i);
			if(flag)
				return flag;
		}
	}
	//可行 换个思路 找可达最远点 牛逼牛逼
	bool canJump(vector<int>& nums, int n)
	{
		int i = 0;
		int reach;
		for ( reach = 0; i < n && i <= reach; ++i)
			reach = i + nums[i] > reach ? i + nums[i] : reach;
		return reach >= n;//思路关键
	}
};
void main_55__Jump_Game()
{
	vector<int> nums = { 2,3,1,1,4 };
	//vector<int> nums = { 3,2,1,0,4 };
	//vector<int> nums = {
	//2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6 };
	
	Solution so;
	cout << so.canJump(nums) << endl;
	system("pause");
}