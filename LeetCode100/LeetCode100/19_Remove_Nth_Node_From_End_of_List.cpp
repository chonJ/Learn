#include<iostream>
using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return head;
		ListNode *left = head;
		ListNode *right = head;
		while (n > 0 && right->next != nullptr)
		{
			right = right->next;
			--n;
		}
		while (right->next != nullptr)
		{
			right = right->next;
			left = left->next;
		}
		
			if (n == 1)
			{
				head = head->next;
				return head;
			}
			left->next = left->next->next;

		
		return head;
	}
};

void main_Remove_Nth_Node_From_End_of_List()   //太菜了
{
	ListNode* head = new ListNode(1);
	ListNode* pre = head;
	for (int i = 2; i < 6; i++)
	{
		ListNode* pNode = new ListNode(i);
		pre->next = pNode;
		pre = pNode;
	}
	Solution so;
	ListNode* res = so.removeNthFromEnd(head, 2);
	while (res != nullptr)
	{
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");
}