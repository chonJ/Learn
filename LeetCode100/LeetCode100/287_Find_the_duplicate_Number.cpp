#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findDuplicate__(vector<int>& nums) {

		if (nums.size() <= 1)
			return -1;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; ++i)
			if (nums[i] == nums[i + 1])
				return nums[i];
		return -1;
	}

	//理解成链表 这就是链表找环的入口问题
	int findDuplicate(vector<int>& nums) {
		if (nums.size() > 1)
		{
			int slow = nums[0];
			int fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			fast = 0;
			while (nums[fast] != nums[slow])
			{
				slow = nums[slow];
				fast = nums[fast];
			}
			return nums[fast];
		}
		return -1;		
	}
};
void main_Find_the_duplicate_Number()
{
	vector<int> nums = {1,3,4,2,2};
	Solution so;
	cout << so.findDuplicate(nums) << endl;
	system("pause");
}