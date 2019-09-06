#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//时间复杂度n平方
	int longestConsecutive_1(vector<int>& nums)
	{
		if (nums.size() < 2)
			return nums.size();
		int res = 0;
		int base = 0;
		int minc = 0;
		int maxc = 0;
		while (base < nums.size())
		{
			int cur = 1;
			int targetr = nums[base];
			while (find(nums, ++targetr))
				cur++;
			int targetl = nums[base];
			while (find(nums, --targetl))
				cur++;
			res = max(res, cur);
			++base;
		}
		return res;
	}
private:
	bool find(vector<int>& nums, int target)
	{
		for (auto a : nums)
			if (a == target)
				return true;
		return false;
	}
//使用 hash_map
public:
	int longestConsecuctive(vector<int> & nums)
	{
		unordered_map<int, int> m;
		int res = 0;
		for (int i : nums)
		{
			if (!m[i])//一定是 map中没有 m[i] 执行   很细节！
			{
				int left = m[i - 1] ? m[i - 1] : 0;
				int right = m[i + 1] ? m[i + 1] : 0;

				//i所在的序列长度为：

				int sum = left + right + 1;
				m[i] = sum;

				//检验是否要更新res
				res = res > sum ? res : sum;

				//更新i所在的序列的两端对应的值  不好理解
				m[i - left] = sum;
				m[i + right] = sum;
			}
			continue;
		}
	}
};