#include<iostream>
#include<stack>
using namespace std;

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* invertTree_digui(TreeNode* root) {
		TreeNode* p = root;
		if (p != NULL)
		{
			invertTree(p->left);
			invertTree(p->right);
			swap(p->left, p->right);
		}
		return root;
	}
	TreeNode* invertTree(TreeNode* root) {

		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* p = s.top();
			s.pop();
			if (p)//用 p->left 之前必须保证 p 非空！
			{
				s.push(p->left);
				s.push(p->right);
				swap(p->left, p->right); 
			}
		}
		return root;
	}
};