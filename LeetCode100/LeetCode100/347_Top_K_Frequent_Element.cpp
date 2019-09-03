#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<unordered_map>
using namespace std;

#define N 1000

class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int K)
	{
		//建立哈希并初始化 value为频次
		unordered_map<int, int> map;
		for (int num : nums)
			map[num]++;

		vector<int> res;
		//  priority_  queue<int,vector<int>,greater<int>> q; 定义小根堆
		//定义大根堆 如下 省略默认参数：
		priority_queue<pair<int, int>> q;
		//要把 second  即value值放在前面 优先队列根据它排序
		for (auto it = map.begin(); it != map.end(); ++it)
			q.push(make_pair(it->second, it->first));
		while (q.size() > map.size() - K)
		{
			res.push_back(q.top().second);
			q.pop();
		}
		return res;
	}
};

void main347()
{
	ifstream f("floatnums.txt");
	float a;
	priority_queue<int, vector<int>, greater<int>> q;
	while (q.size() < N)
	{
		f >> a;
		q.push(a);
	}
	while (!f.eof())
	{
		f >> a;
		if (a > q.top())
		{
			q.pop();
			q.push(a);
		}
	}
	while (!q.empty())
	{
		cout << q.top() << endl;
		q.pop();
	}
	system("pause");
}