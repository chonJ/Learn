#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.size() == 0)
			return res;
		string local;
		vector<vector<char> > table(2, vector<char>());
		table.push_back(vector<char>{'a', 'b', 'c'});
		table.push_back(vector<char>{'d', 'e', 'f'});
		table.push_back(vector<char>{'g', 'h', 'i'});
		table.push_back(vector<char>{'j', 'k', 'l'});
		table.push_back(vector<char>{'m', 'n', 'o'});
		table.push_back(vector<char>{'p', 'q', 'r','s'});
		table.push_back(vector<char>{'t', 'u', 'v'});
		table.push_back(vector<char>{'w', 'x', 'y','z'});
		backTracking(table, res, local, 0, digits);
		return res;
	}
	void backTracking(vector<vector<char> >& table, vector<string>& res,string& local, int index, string& digits)
	{
		if (index == digits.size())
			res.push_back(local);
		else
			for (int i = 0; i < table[digits[index] - '0'].size(); ++i)
			{	
				local.push_back(table[digits[index] - '0'][i]);
				backTracking(table, res, local, index + 1, digits);
				local.pop_back();
			}
	}
};

void main_Letter_Combinations_of_a_Phone_Number()
{
	string a = "23";
	Solution so;
	vector<string> res = so.letterCombinations(a);
	for(auto it : res)
		cout << it << endl;
	system("pause");
}