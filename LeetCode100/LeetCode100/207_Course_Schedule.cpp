#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
		bool canFinish_BFS(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<vector<int> > graph(numCourses, vector<int>(0));
			//定义二维数组graph表示有向图，vector 装 以（坐标）为前提的有哪些/哪些 入 坐标 
			vector<int> in(numCourses, 0);//表示每个定点的入度
			//初始化
			for (auto a : prerequisites)
			{
				graph[a.second].push_back(a.first);
				++in[a.first];//index 入度 + 1
			}
			//定义一个队列用来装 入度为零的index 
			//如果没有入度为0 的index 则 该无向图必定有环
			queue<int> q;
			for (int i = 0; i < numCourses; ++i)
				if (in[i] == 0)
					q.push(i);
			while (!q.empty())
			{
				int t = q.front();
				q.pop();			//把入度为0 的弹出去 并把 所有入它的 入度 - 1
				for (auto a : graph[t])
				{
					--in[a];
					if (in[a] == 0)		//如果 有谁的入度为0了 则把它加入到队列
						q.push(a);
				}
			}
			//如果这时候还有谁的入度不为 0 则必定有环
			for (int i = 0; i < numCourses; ++i)
				if (in[i] != 0)
					return false;
			return true;
		}
	

		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<vector<int> > graph(numCourses, vector<int>(0));
			//定义二维数组graph表示有向图，vector 装 以（坐标）为前提的有哪些/哪些 入 坐标 
			vector<int> visit(numCourses, 0);
			//数组visit来记录访问状态，这里有三种状态，0表示还未访问过，1表示已经访问了，-1表示有冲突
			//初始化
			for (auto a : prerequisites)
			{
				graph[a.second].push_back(a.first);
			}
			for (int i = 0; i < numCourses; ++i)
				if (!canFinishDFS(graph, visit, i))
					return false;
			return true;
		}
		bool canFinishDFS(vector<vector<int> >graph, vector<int> visit, int i)
		{
			if (visit[i] == -1) //冲突 返回false
				return false;
			if (visit[i] == 1)  //改点可用 则直接返回 true
				return true;
			visit[i] = -1;		//判断该点 先将其设为不可用
			for (auto a : graph[i])  //如果 该点有前提点 则分辨判断他们是否可用
				if (!canFinishDFS(graph, visit, a))
					return false;
			visit[i] = 1;			//如果该点没有前提点 或者其前提点都可用 则该点设为可用
			return true;			//	并返回本次判断为true

		}
};
void main_Course_Schedule()
{
	vector<pair<int, int>> prerequisites = { {1,0} };
	Solution so;
	cout << so.canFinish(2,prerequisites) << endl;
	system("pause");
}