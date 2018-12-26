#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//Key is the number and value is its index in the vector.
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			int numberToFind = target - nums[i];

			//if numberToFind is found in map, return them
			if (hash.find(numberToFind) != hash.end()) {
				//
				result.push_back(hash[numberToFind]);
				result.push_back(i);
				return result;
			}

			//number was not found. Put it in the map.
			hash[nums[i]] = i;
		}
		return result;
	}
};

void main_Two_Sum()
{
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	Solution s;
	vector<int> res = s.twoSum(nums, target);
	for (vector<int>::iterator it = res.begin();it != res.end();it++)
		cout << *it << endl;
	system("pause");
}