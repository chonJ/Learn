#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<int> s;
		ListNode* node = head;
		while (node != NULL)
		{
			s.push(node->val);
			node = node->next;
		}
		node = head;
		while (node != NULL && node->val == s.top())
		{
			node = node->next;
			s.pop();
		}
		return node == NULL;
	}

public:
	bool isPalindrome_反转list(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		slow->next = reverseList(slow->next);
		slow = slow->next;
		while (slow != NULL) {
			if (head->val != slow->val)
				return false;
			head = head->next;
			slow = slow->next;
		}
		return true;
	}
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (head != NULL) {
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};