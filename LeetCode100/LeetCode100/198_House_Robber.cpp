#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		vector<int> max = { 0,0 };
		for (int i = 2; i < n + 2; ++i)
		{
			//注意这里要用push_back 而不能写 max[i] = 
			//max.push_back((max[i - 2] + nums[i - 2]) > max[i - 1] ? (max[i - 2] + nums[i - 2]) : max[i - 1]);
			if (max[i - 2] + nums[i - 2] > max[i - 1])
				max.push_back( max[i - 2] + nums[i - 2]);
			else
				max.push_back( max[i - 1]);
		}
		return max[n + 1];
	}
};
void main_House_Robber()
{
	vector<int> nums = {1,2,3,1};
	Solution so;
	cout << so.rob(nums) << endl;
	system("pause");
}