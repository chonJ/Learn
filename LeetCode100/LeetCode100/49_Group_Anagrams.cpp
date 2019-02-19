#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<hash_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams1(vector<string>& strs) {
		int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };

		vector<vector<string>> res;
		hash_map<int, int> map;//<字符串对应的积值，字符串对应组的res【 int 】值>
		hash_map<int, int>::iterator itr;
		
		
		for (vector<string>::iterator it = strs.begin();it != strs.end();++it)
		{
			int key = 1;//unsigned int       long    key的范围大小有一定的影响
			for (string::iterator itt = (*it).begin(); itt != (*it).end(); itt++)
			{
				key *= prime[*itt - 'a'];
			}
			itr = map.find(key);
			if (itr != map.end())
			{
				res[itr->second].push_back(*it);				
			}
			else
			{
				vector<string> t;//t初始化的位置！
				t.push_back(*it);
				res.push_back(t);
				map.insert(pair<int,int>(key, res.size() - 1));
			}
			
		}
		return res;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		for (string s : strs)
		{
			string t = s;
			sort(t.begin(), t.end());
			mp[t].push_back(s);
		}
		vector<vector<string>> anagrams;
		for (auto p : mp)
			anagrams.push_back(p.second);
		return anagrams;
	
	}
};

void main_group_anagrams()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution so;
	vector<vector<string>> res = so.groupAnagrams(strs);
	for (vector<vector<string>>::iterator it = res.begin(); it != res.end(); ++it)
	{
		for (vector<string>::iterator itt = (*it).begin(); itt != (*it).end(); ++itt)
			cout << *itt << "	";
		cout << endl;
	}
	system("pause");
}