#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//需要计算板 导致额外板不同情况的计算
	int trap1(vector<int>& height) {
		if (height.size() < 3)
			return 0;
		int left = 0, right = height.size() - 1;
		int total = 0;
		int ban = 0;
		int i = 1;
		for (; right - left > 1; ++i)
		{
			while (height[left] < i && left < right)
				++left;
			while (height[right] < i && left < right)
				--right;
			if (height[left] >= i)//终止情况有 left==right和left ！= right  且height[left] 和 i 可能 相等   可能  不相等  
			{

				total +=left == right ?  right - left + 1 + height[left] - i : right - left + 1;
			}
		
		}
		int high = i - 1;
		for (i = 0; i < height.size(); ++i)
		{

			if (height[i] > high && left != right)
				ban += high;
			else
				ban += height[i];
		}
	
		return total - ban;
	}

	//牛逼的补水算法  
	int trap(vector<int>& height)
	{
		int left = 0, right = height.size() - 1;
		int res = 0;
		int max_left = 0, max_right = 0;
		while (left < right)
		{
			if (height[left] < height[right])
			{
				if (height[left] > max_left)
					max_left = height[left];
				else
					res += max_left - height[left];
				++left;
			}
			else
			{
				if (height[right] > max_right)
					max_right = height[right];
				else
					res += max_right - height[right];
				--right;
			}
		}
		return res;
	}
};

void main42_Trapping_Rain_Water()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };//6
	vector<int> height1 = { 2,0,2 };//2
	vector<int> height2 = { 0,2,0 };//0
	vector<int> height3 = {5,4,1,2 };//1
	Solution so;
	cout << so.trap(height) << endl;
	cout << so.trap(height1) << endl;
	cout << so.trap(height2) << endl;
	cout << so.trap(height3) << endl;
	system("pause");
}