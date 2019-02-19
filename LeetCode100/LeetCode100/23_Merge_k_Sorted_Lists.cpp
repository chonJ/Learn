#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
	struct compare                    //这个比较器的写法  为啥写在struct中 ？ 注意
	{
		bool operator()(const ListNode* l, const ListNode* r)
		{
			return l->val > r->val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		priority_queue<ListNode *, vector<ListNode *>, compare> q;
		for (auto l : lists)
		{
			if (l)
				q.push(l);
		}
		if (q.empty())
			return NULL;
		ListNode* result = q.top();
		q.pop();
		if (result->next)
			q.push(result->next);
		ListNode* tail = result;
		while (!q.empty())
		{
			tail->next = q.top();
			q.pop();
			tail = tail->next;
			if (tail->next)
				q.push(tail->next);
		}
		return result;
	}
};



void main_Merge_k_Sorted_Lists()
{
	ListNode *p11 = new ListNode(1);
	ListNode *p21 = new ListNode(1);
	ListNode *p31 = new ListNode(2);

	ListNode *p12 = new ListNode(4);
	p11->next = p12;
	ListNode *p13 = new ListNode(5);
	p12->next = p13;

	ListNode *p22 = new ListNode(3);
	p21->next = p22;
	ListNode *p23 = new ListNode(4);
	p22->next = p23;
	
	ListNode *p32 = new ListNode(6);
	p31->next = p32;

	vector<ListNode*> lists;
	lists.push_back(p11);
	lists.push_back(p21);
	lists.push_back(p31);

	Solution so;
	ListNode* res = so.mergeKLists(lists);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");

}