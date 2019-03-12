#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* nodeA = headA;
		ListNode* nodeB = headB;
		while (nodeA != nodeB)
		{
			if (nodeA == NULL)
				nodeA = headB;
			if (nodeB == NULL)
				nodeB = headA;
			if (nodeA == nodeB) //  这里需要补一次判断
				break;
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
		return nodeA;
	}
};
