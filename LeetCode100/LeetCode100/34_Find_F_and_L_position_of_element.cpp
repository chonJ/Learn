#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange1(vector<int>& nums, int target) {
		vector<int> res;
		int len = nums.size();
		if(len == 0)
		{
			res = { -1,-1 };
			return res;
		}
		return res = searchRangeCore(nums, target, 0, len - 1);
	}
	vector<int> searchRangeCore(vector<int>& nums, int target, int left, int right)
	{
		vector<int> res;
		if (nums[left] > target || nums[right] < target)
			return res = { -1,-1 };
		if (nums[left] == target && nums[right] == target)
		{
			res.push_back(left);
			res.push_back(right);
			return res;
		}
		if (right - left == 1)
			if (nums[right] == target)
			{
				res.push_back(right);
				res.push_back(right);
				return res;
			}
			else if (nums[left] != target)
				return res = { -1, - 1 };
		if(nums[(left + right)/2] < target)
			return searchRangeCore(nums, target, (left + right) / 2, right);
		else if(nums[(left + right) / 2] > target)
			return searchRangeCore(nums, target, left, (left + right) / 2);
		else
		{
			if (nums[left] == target)
			{
				int mid = (left + right) / 2;
				while (nums[mid] == target && right - mid > 1)
					mid = (mid + right) / 2;
				if (mid == right - 1)
					mid = mid + 1;
				return searchRangeCore(nums, target, left, mid - 1);
			}

			int mid = (left + right) / 2;
			while (nums[mid] == target && mid - left > 1)
				mid = (left + mid) / 2;
			if (mid == left + 1)
				mid = mid - 1;
			return searchRangeCore(nums, target, mid + 1, right);
			
		}
	}

	vector<int> searchRange(vector<int>& nums, int n, int target) {
		int i = 0, j = n - 1;
		vector<int> ret(2, -1);
		// Search for the left one
		while (i < j)
		{
			int mid = (i + j) / 2;
			if (nums[mid] < target) i = mid + 1;
			else j = mid;
		}
		if (nums[i] != target) return ret;
		else ret[0] = i;

		// Search for the right one
		j = n - 1;  // We don't have to set i to 0 the second time.
		while (i < j)
		{
			int mid = (i + j) / 2 + 1;	// Make mid biased to the right
			if (nums[mid] > target) j = mid - 1;
			else i = mid;				// So that this won't make the search range stuck.
		}
		ret[1] = j;
		return ret;
	}
};

//void main_Find_F_and_L_position_of_element()
void main_Find_F_and_L_position_of_element()
{
	vector<int> a = {7,8};
	Solution so;
	vector<int> res = so.searchRange(a, a.size(),7);
	for (vector<int>::iterator it = res.begin(); it != res.end();++it)
		cout << *it << endl;
	system("pause");
}