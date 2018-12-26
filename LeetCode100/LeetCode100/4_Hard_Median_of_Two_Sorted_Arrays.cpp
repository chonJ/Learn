#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) nums1.swap(nums2);
		int size1 = nums1.size(), size2 = nums2.size(), size = size1 + size2;
		int mid = (size - 1) / 2, l = 0, r = size1 - 1;
		while (l <= r) {
			int m1 = l + ((r - l) >> 1), m2 = mid - m1;
			if (nums1[m1] > nums2[m2]) r = m1 - 1;
			else l = m1 + 1;
		}
		int a = max(r >= 0 ? nums1[r] : INT_MIN, mid - l >= 0 ? nums2[mid - l] : INT_MIN);
		if (size & 1) return a;
		int b = min(l < size1 ? nums1[l] : INT_MAX, mid - r < size2 ? nums2[mid - r] : INT_MAX);
		return (a + b) / 2.0;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int min(int a, int b)
	{
		return a > b ? b : a;
	}
};
void main_findMedianSortedArrays()
{
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2};
	Solution s;
	double res = s.findMedianSortedArrays(nums1, nums2);
	cout << res << endl;
	system("pause");
}