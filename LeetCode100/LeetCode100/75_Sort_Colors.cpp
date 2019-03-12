#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void sortColors_1(vector<int>& nums) {
		sort(nums.begin(),nums.end());
	}
	void sortColors_2(vector<int>& nums) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l < r)
		{
			while (l < r && nums[l] != 2)
				l++;
			while (l < r && nums[r] == 2)
				r--;
			if (l < r )
			{
				swap(nums[l], nums[r]);
			}
			l++; r--;
		}
		l = 0; r = len - 1;
		while (l < r)
		{
			while (l < r && nums[l] != 1)
				l++;
			while (l < r && nums[r] >= 1)
				r--;
			if (l < r )
			{
				swap(nums[l], nums[r]);
			}
			l++; r--;
		}
	}
	//牛逼 清楚！！！！
	void sortColors(vector<int>& nums) {
		int second = nums.size() - 1, zero = 0;
		for (int i = 0; i <= second; ++i)
		{
			while (nums[i] == 2 && i <= second)
				swap(nums[i], nums[second--]);
			while (nums[i] == 0 && i >= zero)
				swap(nums[i], nums[zero++]);
		}
	}
};

void main_Sort_Color()
{
	vector<int> nums = { 1,0};
	for (auto it : nums)
		cout << it << endl;
	Solution so;
	so.sortColors(nums);
	for (auto it : nums)
		cout << it << endl;
	system("pause");
}