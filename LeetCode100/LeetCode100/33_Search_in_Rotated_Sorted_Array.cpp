#include<iostream>
#include<vector>
#include<limits>
using namespace std;

// 第三种解法
class Solution {
public:
	int search1(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		
		return search_unlinear(nums, target, 0, nums.size() - 1);
	}
	int search_unlinear(vector<int>& nums,int target,int start, int end)
	{
		if (start == end)
		{
			if (nums[start] == target)
				return start;
			return -1;
		}
		if (end - start == 1)
		{
			if (nums[start] == target)
				return start;
			if (nums[end] == target)
				return end;
			return -1;
		}
		int mid = (start + end) / 2;
		int left = (start + mid) / 2;
		int right = (mid + end) / 2;
		if (nums[left] < nums[right])	//left < right
			if (target >= nums[left] && target <= nums[right])
				return search_linear(nums, target, left, right);
			else if (target < nums[left])
				if (nums[start] < nums[left])
					return search_linear(nums, target, start, left) + search_unlinear(nums, target, right, end) + 1;
				else
					return search_unlinear(nums, target, start, left) + search_unlinear(nums, target, right, end) + 1; //后项解决一种 start = left的情况
			else
				if (nums[start] < nums[left])
					return  search_unlinear(nums, target, right, end);
				else
					return search_unlinear(nums, target, start, left) + search_linear(nums, target, right, end) + 1;
		else                          //right < left
			if (target >= nums[right] && target <= nums[left])
				if (nums[start] > target)
					return search_linear(nums, target, right, end);
				else
					return search_linear(nums, target, start, left);
			else//(target < nums[right]   he     target > nums[left]
				return search_unlinear(nums, target, left, right);

	}
	int search_linear(vector<int>& nums,int target,int start, int end)
	{
		if (start == end)
		{
			if( nums[start] == target)
				return start;
			return -1;
		}
		if (end - start == 1)
		{
			if (nums[start] == target)
				return start;
			if (nums[end] == target)
				return end;
			return -1;
		}
		if (nums[(start + end) / 2] == target)
			return (start + end) / 2;
		else if (nums[(start + end) / 2] < target)
			return search_linear(nums, target, (start + end) / 2, end);
		else
			return search_linear(nums, target, start, (start + end) / 2);
	}

	//解法二：

	int search2(vector<int>& nums, int target)
	{
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi) 
		{
			int mid = lo + (hi - lo) / 2;
			int num = nums[mid];
			//nums [ mid ] 和 target 在同一段
			/*if ((nums[mid] < nums[0]) == (target < nums[0])) 
			{
				num = nums[mid];
				//nums [ mid ] 和 target 不在同一段，同时还要考虑下变成 -inf 还是 inf。
			}*/
			//else 
			if ((nums[mid] < nums[0]) != (target < nums[0]))
			{
				num = target < nums[0] ? INT_MIN : INT_MAX;
			}

			if (num < target)
				lo = mid + 1;
			else if (num > target)
				hi = mid - 1;
			else
				return mid;
		}
		return -1;
	}
	// 解法三： 推荐算法 易于理解 易于极易
	int search(vector<int>& nums, int target)
	{
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			int num = nums[mid];
			if (num < nums[hi])
				if (target < num || target > nums[hi])
					hi = mid - 1;
				else if (target > num && target <= nums[hi])
					lo = mid + 1;
				else
					return mid;
			else
				if (target < num && target >= nums[lo])
					hi = mid - 1;
				else if (target > num || target < nums[lo])
					lo = mid + 1;
				else
					return mid;			
		}
		return -1;
	}
};

void main_Search_in_Rotated_Sorted_Array()
{
	vector<int> a = { 1,3 };
	Solution so;
	cout << so.search(a, 2) << endl;
	system("pause");
}