#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//暴力区分两种情况 奇回文 和偶回文
	string longestPalindrome_(string s) {
		if (s.empty())
			return s;
		string res = { s[0] };
		int longest = 1;
		for (int i = 0; s[i] != '\0'; i++)
		{
			int zuo = 0;
			int you = 0;
			int flag = 0;
			int len1 = 0;
			int len2 = 0;
			int len3 = 0;

			if ((i > 0 && s[i - 1] == s[i]) || s[i] == s[i + 1])
			{
				len1 = 1;
				int li = i - 1;
				while (li > 0 && s[li--] == s[i])
					++len1;
				zuo = i - len1 + 1;
				int ri = i + 1;
				while (s[i] == s[ri++])
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

			if (len1 > longest || len2 > longest || len3 > longest)
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
	int length(string s, int l, int r)
	{
		int len = 2;
		while (l > 0 && s[--l] == s[++r])
			len += 2;
		return len;
	}
	string save(string s, int zuo, int you)
	{
		string sres;
		for (int i = zuo; i <= you; i++)
			sres += s[i];
		return sres;
	}



	string longestPalindrome(string s)//加#
	{
		string ss;
		//ss += s;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			ss += '#';
			ss += s[i];

		}
		ss += "#";
		cout << ss << endl;
		int resl = 0;
		int resr = 0;
		int res = 1;
		len = ss.size();
		for (int i = 0; i < len; ++i)
		{
			int l = i - 1, r = i + 1;
			while (l >= 0 && r < len && ss[l] == ss[r])
			{
				if (r - l + 1 > res)
				{
					res = r - l + 1;
					resl = l;
					resr = r;
				}

				l--;
				r++;
			}
		}
		string rr;
		for (int i = resl; i <= resr; ++i)
			if (ss[i] != '#')
				rr += ss[i];
		return rr;
	}

	//马拉车
	string dealString(string s)
	{
		string ss;
		//ss += s;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			ss += '#';
			ss += s[i];

		}
		ss += "#";
		return ss;
	}
	int longestPalindromeM(string s)
	{
		if (s.size() == 0)
			return 0;
		string ss = dealString(s);
		vector<int> pArr(ss.size(), 0);

		int C = -1;
		int R = -1;
		int res = INT_MIN;
		for (int i = 0; i < ss.size(); ++i)
		{
			//pArr[C - (i - C)] 处的回文半径 和 i 到R的距离 谁小谁决定 pArr[i]
			pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
			//包括 R <= i 和 pArr[C- (i - C)] == R - i 两种需要继续扩的情况给它进while 继续扩7
			while (i + pArr[i] < ss.size() && i - pArr[i] > -1)
				if (ss[i + pArr[i]] == ss[i - pArr[i]])
					pArr[i]++;
				else
					break;
			if (i + pArr[i] > R)
			{
				R = i + pArr[i];
				C = i;
			}
			res = max(res, pArr[i]);
		}
		return res - 1;
	}

	int min(int a, int b)
	{
		if (a < b)
			return a;
		else
			return b;
	}
	int max(int a, int b)
	{
		return a + b - min(a, b);
	}
};
void main_huiwenzichuan()
{
	string s = "tattarrattat";     // aaa  ababd cbbd 
	//string res = s;
	//res += s[0];
	Solution so;
	string res = so.longestPalindrome(s);
	cout << res.size() << endl;
	for (auto a : res)
	{
		if (a == '\0')
			break;
		if (a != '#')
			cout << a;
	}
	cout << endl;
	string res1 = so.longestPalindrome_(s);
	cout << res1.size() << endl;

	cout << so.longestPalindromeM(s) << endl;
	system("pause");
}