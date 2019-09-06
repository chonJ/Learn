#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void printMatrixClockwisely(vector<vector<int>> nums)
	{
		if (nums.size() == 0 || nums[0].size() == 0)
			return;
		int columns = nums.size();
		int rows = nums[0].size();

		int start = 0;

		while (columns > start * 2 && rows > start * 2)
		{
			printMatrixInCircle(nums, columns, rows, start);
			++start;
		}
	}
private:
	void printMatrixInCircle(vector<vector<int>> nums, int columns, int rows, int start)
	{
		int endX = columns - 1 - start;
		int endY = rows - 1 - start;

		//从左到右
		for (int i = start; i <= endX; ++i)
		{
			int number = nums[start][i];
			printNumber(number);
		}
		//从上到下
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; ++i)
			{
				int number = nums[i][endX];
				printNumber(number);
			}
		}
		//从右到左
		if (start < endX && start < endY)
		{
			for (int i = endX - 1; i >= start; --i)
			{
				int number = nums[endY][i];
				printNumber(number);
			}
		}
		//从下到上
		if (start < endX && start < endY - 1)
		{
			for (int i = endY - 1; i > start; --i)
			{
				int number = nums[i][start];
				printNumber(number);
			}
		}

	}
	void printNumber(int a)
	{
		cout << a << "	";
	}
};