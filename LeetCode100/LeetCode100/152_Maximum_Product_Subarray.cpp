#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		//store the result that is the max we have found so far
		int res = nums[0];

		// imax/imin stores the max/min product of
	// subarray that ends with the current number nums[i]
		for (int i = 1, imax = res, imin = res; i < n; ++i)
		{
			// multiplied by a negative makes big number smaller, small number bigger
			// so we redefine the extremums by swapping them
			if (nums[i] < 0)
				swap(imax, imin);
			
			// max/min product for the current number is either the current number itself
			// or the max/min by the previous number times the current one
			imax = max(nums[i], nums[i] * imax);
			imin = min(nums[i], nums[i] * imin);

			// the newly computed max value is a candidate for our global result
			res = max(imax, res);
		}
		return res;
	}
private:
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int min(int a, int b)
	{
		return a + b - max(a, b);
	}
};
class Solution2 {
public:
	int maxProduct(vector<int>& nums) {
		int len = nums.size();
		int frontProduct = 1;
		int backProduct = 1;
		int res = INT_MIN;

		for (int i = 0; i < len; ++i)
		{
			frontProduct *= nums[i];
			backProduct *= nums[len - 1 - i];
			res = max(res, max(frontProduct, backProduct));
			frontProduct = frontProduct == 0 ? 1 : frontProduct;
			backProduct = backProduct == 0 ? 1 : backProduct;
		}
		return res;
	}
private:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};
void main_Maximum_Product_Subarray()
{
	vector<int> v = { -2,3,-4 };
	Solution2 so;
	cout << so.maxProduct(v) << endl;
	system("pause");
}