#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>

using namespace std;
struct Point {
	int x;
	int y;
};
int max(int a, int b)
{
	return a > b ? a : b;
}
int maxPoints(vector<Point> &points)
{
	int result = 0;

	//对每个点
	for (int i = 0; i < points.size(); ++i)
	{
		int samePoint = 1;				//记录同位置点的个数
		unordered_map<double, int> map;	//创建points[i]所在直线  斜率 - 点个数 的map
		
		//遍历点集
		for (int j = i + 1; j < points.size(); ++j)//只需考虑后面的点
		{
			if (points[i].x == points[j].x && points[i].y == points[j].y)
				samePoint++;
			else if (points[i].x == points[j].x)
				map[INT_MAX]++;
			else
			{
				double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
				map[slope]++;
			}
		}

		int localMax = 0;
		for (auto a : map)
			localMax = max(localMax, a.second);
		localMax += samePoint;
		result = max(result, localMax);
	}
	return result;
}
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}
//避免除法优化
int maxPoints(vector<vector<int>>& points)
{
	int result = 0;

	//对每个点
	for (int i = 0; i < points.size(); ++i)
	{
		int samePoint = 1;				//记录同位置点的个数
		int vertical = 0;				//记录垂直情况点数
		map<pair<int, int>, int> map;	//创建points[i]所在直线  斜率 - //点个数 的map

		//遍历点集
		for (int j = i + 1; j < points.size(); ++j)//只需考虑后面的点
		{
			if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
				samePoint++;
			else if (points[i][0] == points[j][0])
				vertical++;
			else
			{
				int a = points[i][1] - points[j][1];
				int b = points[i][0] - points[j][0];
				int gcd = GCD(a, b);
				a = a / gcd;
				b = b / gcd;

				map[make_pair(a, b)]++;
			}
		}

		int localMax = 0;
		for (auto a : map)
			localMax = max(localMax, a.second);
		localMax += samePoint;
		result = max(vertical, localMax);
		result = max(result, localMax);
	}
	return result;
}

