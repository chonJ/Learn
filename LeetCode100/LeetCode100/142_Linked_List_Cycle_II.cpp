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
	ListNode* detectCycle(ListNode *head) {
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
				f = head;
				while (f != s)
				{
					f = f->next;
					s = s->next;
				}
				return f;
			}
		}
		return NULL;
	}
};
ListNode* linkCreat(vector<int> v, int pos);


void main_Linked_List_Cycle_II()
{
	vector<int> v = { -1,-7,7,-4,19,6,-9,-5,-2,-5 };
	ListNode* head = linkCreat(v, -6);
	//ListNode* node = head;
	//for (int i = 10; i > 0; --i)
	//{
	//	cout << node->val << endl;
	//	if (node->next)node = node->next; else break;
	//}
	Solution so;
	ListNode* res = so.detectCycle(head);
	if(res!= NULL)
	cout << res->val << endl;
	system("pause");
}