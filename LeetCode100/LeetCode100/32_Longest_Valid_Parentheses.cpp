#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		if (len < 2)
			return 0;
		stack<char> helpc;
		stack<int> helpi;
		for (int i = 0; i < len; ++i)
		{
			if (helpc.size() > 0 && s[i] == ')'&& helpc.top() == '(')
			{
				helpc.pop();
				helpi.pop();
			}
			else
			{
				helpc.push(s[i]);
				helpi.push(i);
			}
		}
		
		if (helpi.size() == 0)
			return len;
		int result = 0;
			result = len - helpi.top();
			while (helpi.size() > 1)
			{
				int high = helpi.top();
				helpi.pop();
				int low = helpi.top();
				if (high - low > result)
					result = high - low;
			}
			if (helpi.top() + 1 > result)
				result = helpi.top() + 1;
		return result - 1;
	}
};

void main_Longest_Valid_Parentheses()
{
	string s = "()()((";
	Solution so;

	cout << so.longestValidParentheses(s) << endl;
	system("pause");
}