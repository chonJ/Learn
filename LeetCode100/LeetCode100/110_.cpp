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
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;

		int left = getDepth(root->left);
		int right = getDepth(root->right);

		return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
	int getDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return max(getDepth(root->left), getDepth(root->right)) + 1;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};