#include<iostream>
#include<vector>
using namespace std;

/*Start from its last element, traverse backward to find the first one with index i that satisfy num[i-1] < num[i]. So, elements from num[i] to num[n-1] is reversely sorted.
To find the next permutation, we have to swap some numbers at different positions, to minimize the increased amount, we have to make the highest changed position as high as possible. Notice that index larger than or equal to i is not possible as num[i,n-1] is reversely sorted. So, we want to increase the number at index i-1, clearly, swap it with the smallest number between num[i,n-1] that is larger than num[i-1]. For example, original number is 121543321, we want to swap the '1' at position 2 with '2' at position 7.
The last step is to make the remaining higher position part as small as possible, we just have to reversely sort the num[i,n-1]*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return;
		int index = n - 1;
		while (index > 0)
		{
			if (nums[index - 1] < nums[index])
				break;
			--index;
		}
		if (index == 0)
		{
			reverseSort(nums, 0, n - 1);
			return;
		}
		else
		{
			int val = nums[index - 1];
			int j = n - 1;
			while (j > index)
			{
				if (nums[j] > val)
					break;
				--j;
			}
			swap(nums, j, index - 1);
			reverseSort(nums, index, n - 1);
			return;
		}
	}
public:
	void swap(vector<int> &nums, int i, int j)
	{
		int temp;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	void reverseSort(vector<int> &nums, int start, int end)
	{
		if (start > end)
			return;
		for (int i = start; i <= (start + end) / 2; ++i)
			swap(nums, i, start + end - i);
	}
};
void main_Next_Permutation()
{
	vector<int> a = { 3,2,1 };
	Solution so;
	so.nextPermutation(a);
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << "	" << endl;
	system("pause");

}