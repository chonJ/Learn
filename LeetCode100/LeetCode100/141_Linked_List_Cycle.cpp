#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return head;
		ListNode* f = head;
		ListNode* s = head;
		while (f->next != NULL && f->next->next != NULL)
		{
			f = f->next->next;
			s = s->next;
			if (f == s)
			{
				
					return true;
			}
		}
		return false;
	}
};
ListNode* linkCreat(vector<int> v, int pos)
{
	ListNode* head;
	ListNode*  node;
	ListNode*  find;
	if (v.size() == 0)
		return NULL;
	head = new ListNode(v[0]);
	if (v.size() == 1)
		return head;
	node = head;
	for (vector<int>::iterator it = v.begin() + 1; it != v.end(); ++it)
	{
		ListNode* cur = new ListNode(*it);
		node->next = cur;
		node = cur;
	}
	find = head;
	if(pos != -1)
		while (find != NULL)
		{
			if (find->val == pos)
			{
				node->next = find;
				return head;
			}
			find = find->next;
		}
	return head;
}

void main_Linked_List_Cycle()
{
	vector<int> v = { -1,-7,7,-4,19,6,-9,-5,-2,-5 };
	ListNode* head = linkCreat(v, 6);
	//ListNode* node = head;
	//for (int i = 10; i > 0; --i)
	//{
	//	cout << node->val << endl;
	//	if (node->next)node = node->next; else break;
	//}
	Solution so;
	cout << so.hasCycle(head) << endl;
	system("pause");
}