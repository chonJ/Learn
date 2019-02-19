#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>


//    比较器   注意一下
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};
bool comparator(Interval a, Interval b)
{
	return (a.start < b.start);
}

class Solution {
public:
	//如果能保证原序列升序的话 这种方法是可以的
	vector<Interval> merge_shengxu(vector<Interval>& intervals) {
		
		if (intervals.size() < 2)
			return intervals;
		vector<Interval> res;
		stack<Interval> help;
		int i = 0, in = 1, j = intervals.size() - 1, jn = intervals.size() - 2;
		res.push_back(intervals[i]);
		help.push(intervals[j]);
		while (i < j   && res[res.size() -1].end < help.top().start)
		{
			if (i > 0 && res[res.size() - 1].end > intervals[i].start)
			{
				Interval a(res[res.size() - 1].start, intervals[i].end);
				res.pop_back();
				res.push_back(a);
			}
			else if(i > 0)
				res.push_back(intervals[i]);
			++i;
			if (i <= j)
			{
				if (j < intervals.size() - 1 && help.top().start < intervals[j].end)
				{
					Interval a(intervals[j].start, help.top().end);
					help.pop();
					help.push(a);
				}
				else if(j < intervals.size() - 1)
					res.push_back(intervals[i]);
			}
			--j;
		}
		if (res[res.size() - 1].end >= help.top().start)
		{
			//if (res[res.size() - 1].start <= help.top().end)
			//{
				int max = res[res.size() - 1].end > help.top().end ? res[res.size() - 1].end : help.top().end;
				int min = res[res.size() - 1].start < help.top().start ? res[res.size() - 1].start : help.top().start;
				Interval n(min, max);
				res.pop_back();
				res.push_back(n);
				help.pop();
			/*}
			else
			{
				Interval n = res[res.size() - 1];
				res.pop_back();
				res.push_back(help.top());
				help.pop();
				help.push(n);
			}*/
		}
		while (!help.empty())
		{
			res.push_back(help.top());
			help.pop();
		}
		return res;
	}
	//自写方法
	vector<Interval> merge_self(vector<Interval>& intervals) {
		if (intervals.size() < 2)
			return intervals;
		vector<Interval> res;
		
		res.push_back(intervals[intervals.size() - 1]);
		intervals.pop_back();

		while(intervals.size() > 0)
		{
			
			//if (res[res.size() - 1].start > intervals[intervals.size()-1].end)
			//{
				stack<Interval> help;
				while (res.size() > 0 && res[res.size() - 1].start > intervals[intervals.size() - 1].end)
				{
					cout << res[res.size() - 1].start << "	" << res[res.size() - 1].end << "	拿出来";
					cout << intervals[intervals.size() - 1].start << "	" << intervals[intervals.size() - 1].end << "	待入"<<endl;
					help.push(res[res.size() - 1]);
					res.pop_back();
				}
				
				
			//}
				if(res.size() == 0)
				{
					res.push_back(intervals[intervals.size() - 1]);
					intervals.pop_back();
				}
			else if (res[res.size() - 1].end >= intervals[intervals.size() - 1].start)
			{

				int max = res[res.size() - 1].end > intervals[intervals.size() - 1].end ? res[res.size() - 1].end : intervals[intervals.size() - 1].end;
				int min = res[res.size() - 1].start < intervals[intervals.size() - 1].start ? res[res.size() - 1].start : intervals[intervals.size() - 1].start;
				Interval n(min, max);
				res.pop_back();
				//res.push_back(n);
				intervals.pop_back();
				intervals.push_back(n);
			}
			else
			{
				res.push_back(intervals[intervals.size() - 1]);
				intervals.pop_back();
			}
			while (!help.empty())
			{
				res.push_back(help.top());
				help.pop();
			}
			//cout << "res :    ";
			//for (auto it : res)
				//cout <<  it.start << "	" << it.end <<"	";
			//cout << endl;
		}
		//cout << endl;
		//cout << "fengexian" << endl;
		//cout << endl;
		return res;
		
	}
	//先sort 方法
	vector<Interval> merge(vector<Interval>& intervals)
	{
		if (intervals.size() < 2)
			return intervals;
		vector<Interval> res;
		//sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });

		
		sort(intervals.begin(), intervals.end(),comparator);
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (res.back().end >= intervals[i].start)
				res.back().end = res.back().end > intervals[i].end ? res.back().end : intervals[i].end;
			else
				res.push_back(intervals[i]);
		}
		return res;
	}
	
};


void main_Merge_intervals()
{
	vector<Interval> intervals = { {1,3},{2,6},{8,10},{15,18} };
	vector<Interval> intervals1 = { {1,4},{0,2},{3,5}};
	vector<Interval> intervals2 = { {1,5},{0,4} };
	vector<Interval> intervals3 = { {1,5},{0,0} };
	Solution so;
	vector<Interval> res = so.merge(intervals1);
	for (vector<Interval>::iterator it = res.begin(); it != res.end(); it++)
		cout << (*it).start << "	" << (*it).end << endl;
	system("pause");
}