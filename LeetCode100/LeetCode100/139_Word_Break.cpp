#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> word;
		if (wordDict.size() == 0)
			return false;
		for (auto it : wordDict)
			word.insert(it);
		return wordBreak(s, word);
	}
private:
	bool wordBreak(string s, unordered_set<string> word)
	{
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if(dp[j])
				{
					string w = s.substr(j, i - j);
					if (word.find(w) != word.end())
					{
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
};
void main_Word_break()
{
	string s = "catsandog";
	vector<string> wordDict = { "cats", "andog" };
	Solution so;
	cout << so.wordBreak(s,wordDict) << endl;
	system("pause");
}
