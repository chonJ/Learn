#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf_my_poor(vector<int>& nums) {
		vector<int> pre = { 1 };
		vector<int> back = { 1 };
		for (int i = 1; i < nums.size(); ++i)
		{
			pre.push_back(pre[i - 1] * nums[i - 1]);
			back.push_back(back[i - 1] * nums[nums.size() - i]);
		}
		// vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
			//res.push_back(pre[i] * back[nums.size() -1 - i]);
			pre[i] = (pre[i] * back[nums.size() - 1 - i]);
		return pre;
	}
	vector<int> productExceptSelf__(vector<int>& nums) {
		vector<int> res = { 1 };

		for (int i = 1; i < nums.size(); ++i)
			res.push_back(res[i - 1] * nums[i - 1]);
		int right = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
	//能一次一起做了的就不要分两次循环

	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n,1);
		int left = 1, right = 1;
		for (int i = 0; i < n; ++i)
		{
			res[i] *= left;
			left *= nums[i];
			res[n - 1 - i] *= right;
			right *= nums[n - 1 - i];
		}
		return res;
	}
};
void main_Product_of_Array_Except_Self()
{
	vector<int> nums = { 1,2,3,4 };
	Solution so;
	vector<int> res = so.productExceptSelf(nums);
	for (auto a : res)
		cout << a << endl;
	system("pause");
}