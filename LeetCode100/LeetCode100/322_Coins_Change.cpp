#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int MAX = amount + 1;
		vector<int> dp(amount + 1, MAX);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i)
			for (int j = 0; j < coins.size(); ++j)
				if (coins[j] <= i)
					dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
		return dp[amount] > amount ? -1 : dp[amount];
	}
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
};
void main_Coins_Changes()
{
	vector<int> coins = { 1,2,5 };
	Solution so;
	cout << so.coinChange(coins, 11);

	system("pause");
}