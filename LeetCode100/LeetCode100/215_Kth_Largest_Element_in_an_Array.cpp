#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

class Solution_my {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};


//partition 
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		k = nums.size() - k;
		int left = 0;
		int right = nums.size() - 1;
		while(left < right)
		{
			const int position = partition(nums, left, right);// j 是第一次随机找得参考值的 位置
			
			for (auto a : nums)
				cout << a << "	" ;
			cout << endl;
			cout <<position<< endl;
			if (position < k)
				left = position + 1;
			else if (position > k)
				right = position - 1;
			else
				break;
		}
		return nums[k];
	}
private:
	int partition(vector<int> &nums, int left, int right)
	{
		int i = left;
		int j = right + 1;
		while (true)
		{
			while (i < right && nums[++i] < nums[left]);
			while (j > left && nums[--j] > nums[left]);
			if (i >= j)
				break;
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
		int temp = nums[left];
		nums[left] = nums[j];
		nums[j] = temp;
		for (auto a : nums)
			cout << a << "	";
		cout << endl;
		cout << j << endl;
		return j;
	}
};
void main_Kth_Largest_Element_in_an_Array()
{
	vector<int> nums = { 3,2,1,5,6,4 };
	Solution so;
	
	cout << so.findKthLargest(nums, 2) << endl;
	system("pause");
}