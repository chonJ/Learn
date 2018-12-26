#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		
		int res = 0, b = 0;
		for (int i = 0;s[i] != '\0';++i)
		{
			int k = 1, j = i;
			while (--j >= b && s[j] != s[i])
			{
				
				++k;
			}
			if(j >= b && s[j] == s[i])   //aab 情况 j >= b 为什么要有等于
				b = j+1;
			if (k > res)
				res = k;
		}
		return res;
	}
};
void main_Longest_Substring_Without_Repeating_Characters()
{
	string s = "abcabcbb";
	cout << s[0] << endl;
	Solution so;
	int res = so.lengthOfLongestSubstring(s);
	cout << res << endl;
	system("pause");
}