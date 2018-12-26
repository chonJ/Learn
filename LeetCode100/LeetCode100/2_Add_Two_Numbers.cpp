#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
		if (l1 == NULL && l2 == NULL)
		{
			if(flag == 0)
			return l1;
			else
			{
				Node->val = 1;
				Node->next = l1;
			}
		}
		else if (l1 != NULL && l2 != NULL)
			{
				int sum = l1->val + l2->val + flag;
				if (sum >= 10)
					flag = 1;
				else
					flag = 0;
				Node->val = sum % 10;
				Node->next = addTwoNumbers(l1->next, l2->next);
			}
			else if (l1 != NULL)
			{
				int sum = l1->val + flag;
				if (sum >= 10)
					flag = 1;
				else
					flag = 0;
				Node->val = sum % 10;
				Node->next = addTwoNumbers(l1->next, l2);
			}
			else
			{
				int sum = l2->val + flag;
				if (sum >= 10)
					flag = 1;
				else
					flag = 0;
				Node->val = sum % 10;
				Node->next = addTwoNumbers(l1, l2->next);
			}
			
		return Node;
	}
private:
	int flag = 0;
};
void main_Add_Two_Numbers()
{
	ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
	l1->val = 2;
	ListNode* pNode1 = (ListNode*)malloc(sizeof(ListNode));
	pNode1->val = 4;
	l1->next = pNode1;
	ListNode* pNode2 = (ListNode*)malloc(sizeof(ListNode));
	pNode2->val = 3;
	pNode1->next = pNode2;
	pNode2->next = NULL;

	ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
	l2->val = 5;
	ListNode* pNode3 = (ListNode*)malloc(sizeof(ListNode));
	pNode3->val = 6;
	l2->next = pNode3;
	ListNode* pNode4 = (ListNode*)malloc(sizeof(ListNode));
	pNode4->val = 6;
	pNode3->next = pNode4;
	pNode4->next = NULL;

	Solution s;
	ListNode* res = s.addTwoNumbers(l1, l2);
	for (;res != NULL;)
	{
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");
}