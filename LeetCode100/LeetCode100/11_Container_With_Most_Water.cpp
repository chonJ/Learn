#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		//if (height.size() < 2)
		//	return 0;
		int ans = 0;
		int l = 0;
		int r = height.size() - 1;
		while (l < r)
		{
			int h = min(height[l], height[r]);
			ans = max(ans, h*(r - l));
			if (height[l] < height[r])
				++l;
			else
				--r;
		}
		return ans;
	}
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;

	}
};

void main_11_Container_With_Most_Water()
{
	vector<int> h = { 1,8,6,2,5,4,8,3,7 };
	Solution so;
	int ans = so.maxArea(h);


	cout << "res :" << ans << endl;
	system("pause");
}