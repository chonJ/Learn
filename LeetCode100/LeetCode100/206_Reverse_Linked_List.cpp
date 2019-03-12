#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		/*迭代
		 if(head == NULL)
			 return head;
		 ListNode* newnext = NULL;
		// ListNode* forward = head;
		 while(head != NULL)
		 {
			  ListNode* forward;
			 forward = head->next;
			 head->next = newnext;
			 newnext = head;
			 head = forward;
		 }
		 return newnext; */

		 //递归
		if (head == NULL)return head;
		return reverseList(NULL, head, head->next);
	}
	ListNode* reverseList(ListNode* pre, ListNode* head, ListNode* next)
	{
		head->next = pre;
		if (next == NULL)
			return head;

		return reverseList(head, next, next->next);
	}
};
