#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//这是一道没思路的题哦 记得多看几遍小老弟
class Solution {
public:
	//基本思路及代码
	int minDistance_base(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i)
			dp[i][0] = i;
		for (int j = 1; j <= n; ++j)
			dp[0][j] = j;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (word1[i - 1] == word2[j - 1])//注意 ： 计算dp[i][j]时 判断的是 word1[i - 1] 和 word2[j - 1]
					dp[i][j] = dp[i - 1][j - 1];//相等 无需操作
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;//（不等 交换，（删除一个，插入一个））
		return dp[m][n];
	}
	int minDistance_good(string word1, string word2) {
		int m = word1.size(), n = word2.size();//向Word2变 则确定了 最后的pre[pre.size()]为 转向Word2的值
		vector<int> cur(n + 1, 0), pre(n + 1, 0);
		for (int j = 1; j <= n; ++j)
			pre[j] = j;
		for (int i = 1; i <= m; ++i)
		{
			cur[0] = i;
			for (int j = 1; j <= n; ++j)
				if (word1[i - 1] == word2[j - 1])
					cur[j] = pre[j - 1];
				else
					cur[j] = min(pre[j - 1],min(pre[j], cur[j - 1] )) + 1;
			
			swap(cur, pre);
		}
		return pre[n];
	}
	//best
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size(),pre;//pre 用作记录[i - 1][j - 1] 的值
		vector<int> cur(n + 1,0);
		for (int i = 1; i <= n; ++i)
			cur[i] = i;
		for (int j = 1; j <= m; ++j)
		{
			pre = cur[0]; //i = 0 时 要记录前一列 i= 0 的值 作为本次循环求i= 0的参考
			cur[0] = j;
			for (int i = 1; i <= n; ++i)
			{
				int temp = cur[i];
				if (word1[j - 1] == word2[i - 1])//谁是i 谁是j 要注意
					cur[i] = pre;
				else
					cur[i] = min(pre, min(cur[i], cur[i - 1])) + 1;
				pre = temp;
			}
		}
		return cur[n];
	}
};

void main_Edit_Distance()
{
	string word1 = "intention";
	string word2 = "execution";
	string word3 = "horse";
	string word4 = "ros";
	Solution so;
	cout << so.minDistance(word3, word4) << endl;
	system("pause");
}