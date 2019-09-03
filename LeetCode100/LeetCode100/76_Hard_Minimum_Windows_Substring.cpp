#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	//这个题肯定是只能靠背了
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size()) {
			if (map[s[end++]]-- > 0) counter--; //in t
			while (counter == 0) { //valid 当第一个“内元素”要循环增前
				if (end - begin < d)  d = end - (head = begin);
				int a = map[s[begin]];
				if (map[s[begin++]]++ == 0) 
					counter++;  //make it invalid
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}

};

void main76_Hard_Minimum_Windows_Substring()
{
	string s = "eADOBECBANC", t = "ABC";
	string res;
	res = s.substr(0, 2);//(起始位置，个数)
	cout << s << res;
	Solution so;
	cout << so.minWindow(s, t) << endl;
	system("pause");
}