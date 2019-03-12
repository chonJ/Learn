#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
ListNode* linkCreat(vector<int> v, int pos);

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL ||head->next == NULL )// 错了！ 多判断了一个head->next->next
			return head;
		// 第一步 把链表切为两段
		ListNode* f = head;
		ListNode* s = head;
		ListNode* pre = NULL;
		while(f != NULL && f->next != NULL)// 错了！多判断了一个head->next->next
		{
			f = f->next->next;
			pre = s;
			s = s->next;
		}
		pre->next = NULL;

		 //第二步 对每一段链表排序
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(s);
		
		//第三步 合并
		return merge(l1, l2);
	}
	ListNode* merge(ListNode* l1, ListNode* l2)// 重要！
	{
		//ListNode n(0);
		ListNode* n =new ListNode(0);// 留意！
		ListNode* p = n;
		while (l1 != NULL && l2 != NULL)  
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;// 错了！马虎写成 l1
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1 != NULL)
			p->next = l1;
		if (l2 != NULL)
			p->next = l2;
		return n->next;
	}
};
void main_Sort_List()
{
	vector<int> v = { -1,5,3,4,0 };
	ListNode* head = linkCreat(v,99);
	
	Solution so;
	ListNode* res = so.sortList(head);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");
}