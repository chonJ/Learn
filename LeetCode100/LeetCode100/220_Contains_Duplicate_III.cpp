#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long> record;
		for (int i = 0; i < nums.size(); ++i)
		{
			//if(record.find(nums[i]) != record.end())
			//    return true;
			if (record.lower_bound((long long)nums[i] - (long long)t) != record.end() && 
				(*record.lower_bound((long long)nums[i] - (long long)t)) <= 
				((long long)nums[i] + (long long)t))   //这里的int 加法要考虑溢出
				return true;

			record.insert(nums[i]);

			//保持record中最多有k个元素
			if (record.size() == k + 1)
				record.erase(nums[i - k]); //删除的方式注意下
		}
		return false;
	}
};