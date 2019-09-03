#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i)
		{
			int target = -nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back)
			{
				int sum = nums[front] + nums[back];
				if (sum < target)
					++front;
				else if (sum > target)
					--back;
				else
				{
					res.push_back({ nums[i],nums[front],nums[back] });
					while (front < back && res.back()[1] == nums[front])	++front;
					while (front < back && res.back()[2] == nums[back])	--back;
				}
			}
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])	++i;
		}
		return res;
	}

	vector<vector<int>> threeSum_(vector<int> nums)
	{
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i)
		{
			int target = -nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back)
			{
				if (nums[front] + nums[back] == target)
				{
					res.push_back({ nums[i],nums[front],nums[back] });
					while (front < back && nums[front] == res.back()[1])
						++front;
					while (front < back && nums[back] == res.back()[2])
						--back;
				}
				else if (nums[front] + nums[back] > target)
					--back;
				else
					++front;
			}
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				++i;
		}
		return res;
	}
};
void main3sum()
{
	vector<int> a = {-1,0,1,2,-1,-4};
	Solution so;
	vector<vector<int> > b = so.threeSum_(a);
	for (int i = 0; i < b.size(); ++i)
	{
		for (int j = 0; j < 3; ++j)
			cout << b[i][j] << "	";
		cout << endl;
	}
	system("pause");
}