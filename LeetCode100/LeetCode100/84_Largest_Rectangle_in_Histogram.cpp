#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea_1(vector<int>& heights) {
		if (heights.size() == 0)
			return 0;
		long max = 0,cur = 0;
		
		for (int i = 0; i < heights.size(); ++i)
		{
			cur = 0; int left = 0; int right = 0;
			//向左
			while (i - left >= 0 && heights[i - left++] >= heights[i])
				cur += heights[i];
			//向右
			//while (i + right <= heights.size() - 1 && heights[i + right++] >= heights[i])
				//cur += heights[i];
			//cur -= heights[i];//减去多加的一个
			max = cur > max ? cur : max;
		}
		return max;
	}
	//牛逼算法
	int largestRectangleArea(vector<int>& heights) {
		int res = 0,cur = 0;
		heights.push_back(0);//末尾加0 满足最后下降条件
		stack<int> stack;	 //装的是元素下标

		int i = 0;
		while (i < heights.size())
		{
			if (stack.empty() || heights[i] >= heights[stack.top()])//如果是第一个 或者 保持升势 则压入栈
				stack.push(i++);
			else
			{
				int t = stack.top();// 接下来要计算的 高度
				stack.pop();
				int l = stack.empty() ? i : i - stack.top() - 1;
				cur = heights[t] * l;
				//计算该高度下的值 如果栈中还有大于heights[i]的值则会下次循环在这里计算
				// 直到 栈为空 或 栈顶的值 小于heights[i] 则下次循环进入if
				res = res > cur ? res : cur;
				//res = res > heights[t] * (stack.empty() ? i : i - stack.top() - 1) ? res : heights[t] * (stack.empty() ? i : i - stack.top() - 1);
			}
		}
		return res;
	}
};

void main_84_Largest_Rectangle_in_Histogram()
{
	vector<int> heights = { 2,1,5,6,2,3};
	vector<int> heights1 = { 2 };
	Solution so;
	cout << so.largestRectangleArea(heights) << endl;
	system("pause");
}