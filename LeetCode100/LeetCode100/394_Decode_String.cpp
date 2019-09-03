#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return decodeString(s, i);

	}
	string decodeString(string s,int &i) {
		string res;
		while (i < s.length() && s[i] != ']')
		{
			if (!isdigit(s[i]))
				res += s[i++];
			else
			{
				int n = 0;
				while (i < s.length() && isdigit(s[i]))
					n = n * 10 + (s[i++] - '0');
				
				i++;//跳过 '['
				string t = decodeString(s, i);
				i++;//跳过']'
				while (n-- > 0)
					res += t;
			}
		}
		return res;
	}
};

void main_Decode_String()
{
	string s1 = "3[a]2[bc]";
	string s2 = "3[a2[c]]";
	string s3 = "2[abc]3[cd]ef";
	Solution so;
	cout  <<  so.decodeString(s1) <<  endl;
	cout << so.decodeString(s2) << endl;
	cout << so.decodeString(s3) << endl;
	system("pause");
}
