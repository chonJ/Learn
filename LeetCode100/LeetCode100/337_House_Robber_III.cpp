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
	int tryrob(TreeNode* root, int& l, int& r)
	{
		if (root == NULL)
			return 0;
		int ll = 0, lr = 0, rl = 0, rr = 0;
		l = tryrob(root->left, ll, lr);
		r = tryrob(root->right, rl, rr);

		return max(root->val + ll + lr + rl + rr, l + r);
	}
	int rob(TreeNode* root) {
		int l = 0, r = 0;
		return tryrob(root, l, r);
	}
private:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};
void main______()
{

	system("pause");
}