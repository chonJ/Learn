#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		else if (l2 == nullptr)
			return l1;
		ListNode *head;
		if (l1->val < l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}
		ListNode *node = head;
		while (l1 != nullptr || l2 != nullptr)
		{
			if (l1 == nullptr)
			{
				node->next = l2;
				break;
			}
			if (l2 == nullptr)
			{
				node->next = l1;
				break;
			}
			if (l1->val < l2->val)
			{
				node->next = l1;
				l1 = l1->next;
				node = node->next;
			}
			else
			{
				node->next = l2;
				l2 = l2->next;
				node = node->next;
			}
		}
		return head;
	}
};
void main_Merge_Two_Sorted_Lists()
{
	ListNode *l1 = new ListNode(1);
	ListNode *Node1 = new ListNode(2);
	l1->next = Node1;
	ListNode *Node2 = new ListNode(4);
	Node1->next = Node2;

	ListNode *l2 = new ListNode(1);
	ListNode *Nodee1 = new ListNode(3);
	l2->next = Nodee1;
	ListNode *Nodee2 = new ListNode(4);
	Nodee1->next = Nodee2;

	Solution ss;
	ListNode *res = ss.mergeTwoLists(l1, l2);
	while (res != nullptr)
	{
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");
}