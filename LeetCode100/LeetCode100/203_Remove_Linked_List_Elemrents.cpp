#include<iostream>

using namespace std;



  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* removeElements_1(ListNode* head, int val) {
		// if(head == NULL)
		  //   return NULL;

		while (head != NULL && head->val == val)
		{
			ListNode* delNode = head;
			head = delNode->next;
			delete delNode;
		}
		if (head == NULL)
			return NULL;

		ListNode* cur = head;
		while (cur->next != NULL)
		{
			if (cur->next->val == val)
			{
				//删除cur->next
				ListNode* delNode = cur->next;
				cur->next = delNode->next;
				delete delNode;
			}
			else
				cur = cur->next;
		}
		return head;
	}
	//采用虚拟节点
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode* cur = dummyHead;
		while (cur->next != NULL)
		{
			if (cur->next->val == val)
			{
				//删除cur->next
				ListNode* delNode = cur->next;
				cur->next = delNode->next;
				delete delNode;
			}
			else
				cur = cur->next;
		}
		ListNode* resNode = dummyHead->next;
		delete dummyHead;
		return resNode;
	}
};