#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return s;
		string res = { s[0] };
		int longest = 1;
		for (int i = 0;s[i] != '\0';i++)
		{
			int zuo = 0;
			int you = 0;
			int flag = 0;
			int len1 = 0;
			int len2 = 0;
			int len3 = 0;

			if ((i > 0 && s[i - 1] == s[i] ) || s[i] == s[i+1])
			{
				len1 = 1;
				int li = i - 1;
				while (li > 0 && s[li--] == s[i])
					++len1;
				zuo = i - len1 + 1;
				int ri = i + 1;
				while ( s[i] == s[ri++])
					++len1;
				you = zuo + len1 - 1;
			}
			 if (i > 0 && s[i - 1] == s[i + 1])
			{
				len2 = length(s, i - 1, i + 1) + 1;
				flag = 1;
			}
			 if (s[i] == s[i + 1])
			{
				len3 = length(s, i, i + 1);
				flag = 1;
			}
			 
			if (len1 > longest || len2 >longest ||len3 > longest)
			{
				if (len1 > len2 && len1 > len3)
				{
					res = save(s, zuo, you);
					longest = len1;
				}
				else
				{
					int lel = len2 > len3 ? len2 : len3;
					res = save(s, i - ((lel - 1) >> 1), i + ((lel) >> 1));
					longest = lel;
				}
				
					
			}
			
		}
		return res;
	}
	int length(string s,int l, int r)
	{
		int len = 2;
		while (l > 0 && s[--l] == s[++r])
			len += 2;
		return len;
	}
	string save(string s,int zuo,int you)
	{
		string sres;
		for (int i = zuo;i <= you;i++)
			sres += s[i];
		return sres;
	}
};
void main_Longest_Palindromic_Substring()
{
	string s = "tattarrattat";     // aaa  ababd cbbd 
	//string res = s;
	//res += s[0];
	Solution so;
	string res = so.longestPalindrome(s);
	cout << res << endl;
	system("pause");
}