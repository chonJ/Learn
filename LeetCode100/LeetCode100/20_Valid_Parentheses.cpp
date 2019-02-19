#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0)
			return true;
		if (s.size() & 1 == 1)
			return false;
		stack<char> a;
		if (s[0] == '(' || s[0] == '{' || s[0] == '[' || s[0] == '\0')
			a.push(s[0]);
		else
			return false;
		for (int i = 1; s[i] != '\0'; ++i)
		{
			
			if (!a.empty() && ((a.top() == '(' && s[i] == ')') || (a.top() == '[' && s[i] == ']') || (a.top() == '{' && s[i] == '}')))
				a.pop();
			else if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{' && s[i] != '}')
				return false;
			else
				a.push(s[i]);
		}
		/*if (a.empty())
			return true;
		else
			return false;*/
		return a.empty();
	}
};
//大牛的优化
/*
  bool isValid(string s) {
		stack<char> paren;
		for (char& c : s) {
			switch (c) {
				case '(':
				case '{':
				case '[': paren.push(c); break;
				case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
				case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
				case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
				default: ; // pass
			}
		}
		return paren.empty() ;
	}
*/


void main_Valid_Parentheses()
{
	string s = "()]{[]}";
	cout << s.size() << endl;
	Solution so;
	bool res = so.isValid(s);
		cout << res << endl;
	system("pause");
}