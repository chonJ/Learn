#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (!s.empty() && p.empty())
			return false;
		char* str = new char[s.size()+1];    //加1 把最后的'\0'也拷贝过去
		strcpy(str, s.data());
		char* pattern = new char[p.size()+1];
		strcpy(pattern, p.data());
		bool res = matchCore(str, pattern);
		delete str, pattern;
		return res;
	}
	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*pattern == '\0' && *str != '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*str == *pattern || (*pattern == '.'&& *str != '\0'))
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			else
				return matchCore(str, pattern + 2);
		}
		if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
			return matchCore(str + 1, pattern + 1);
		else
			return false;
	}
};

class Solution1 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())    return s.empty();

		if ('*' == p[1])
			// x* matches empty string or at least one character: x* -> xx*
			// *s is to ensure s is non-empty
			return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)); 
													//从左向右 依次判断 并且遵从 或左为1 不看右 与左为0不看右
		else
			return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
	}
};

void main_10_Regular_Expression_Matching()
{
	string s = "";
	string p = ".*";
	Solution1 so;
	bool a = so.isMatch(s, p);
	cout << a << endl;
	system("pause");
}