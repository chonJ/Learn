#include<iostream>
#include<vector>
using namespace std;

class Solution11 {
public:
	int maxProfit(vector<int>& prices) {
		int prebuy(0), buy(INT_MIN), presell(0), sell(0);
		for (int i = 0; i < prices.size(); ++i)
		{
			prebuy = buy;
			buy = max(presell - prices[i],buy);
			presell = sell;
			sell = max(prebuy + prices[i], sell);
			
		}
		return sell;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};
void main_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown()
{
	vector<int> prices = { 1,2,3,0,2 };
	Solution11 so;
	cout << so.maxProfit(prices) << endl;
	system("pause");
}