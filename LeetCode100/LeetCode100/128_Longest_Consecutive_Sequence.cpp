#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//时间复杂度 n平方
	int longestConsecutive_1(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int res = 0;
		int base = 0;
		int minc = 0;
		int maxc = 0;
		while (base < nums.size() )
		{
			int cur = 1;
			int targetr = nums[base];
			while (find(nums, ++targetr))
				cur += 1;
		
			int targetl = nums[base];
			while (find(nums, --targetl))
				cur += 1;
			
			res = max(res, cur);
			++base;
		}
		return res;
	}
private:
	bool find(vector<int>& nums,  int target)
	{
		
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == target)
				return true;		
		return false;
	}
	// 使用 hash_map
public:
	int longestConsecutive(vector<int>& nums) 
	{
		unordered_map<int, int> m;
		int res = 0;
		for (int i : nums)
		{
			if (!m[i]) //如果 map中没有 m[i] 
			{
				int left = (m[i - 1] ? m[i - 1] : 0);
				int right = (m[i + 1] ? m[i + 1] : 0);

				//i 所在的序列长度为 
				int sum = left + right + 1;
				m[i] = sum;

				//检验 res 是否 要更新
				res = res > sum ? res : sum;

				//更新 i 所在序列两端的 对应值
				m[i - left] = sum;
				m[i + right] = sum;
			}
			continue;
		}
		return res;
		
	}
};
void main_Longest_Consecutive_Sequence()
{
	vector<int> v = { 100,4,200,1,3,2 };
	Solution so;
	cout << so.longestConsecutive(v) << endl;
	
	system("pause");
}