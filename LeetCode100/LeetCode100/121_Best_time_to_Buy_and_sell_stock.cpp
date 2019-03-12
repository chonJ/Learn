#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;

		int min = prices[0], pro = 0;
		for (int i = 1; i < prices.size(); ++i)
		{

			pro = prices[i] - min > pro ? prices[i] - min : pro;

			min = prices[i] < min ? prices[i] : min;

		}
		return pro;
	}
};

void main_Best_time_to_Buy_and_sell_stock()
{
	vector<int> prices = { 7,1,5,3,6,4 };
	Solution so;
	cout << so.maxProfit(prices) << endl;
	system("pause");
}