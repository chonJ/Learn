#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		travel(root);
		return root;
	}
	void travel(TreeNode* root)
	{
		if (!root)
			return;
		if (root->right)
			travel(root->right);
		root->val = (cur_sum += root->val);
		if (root->left)
			travel(root->left);
	}
private:
	int cur_sum = 0;
};