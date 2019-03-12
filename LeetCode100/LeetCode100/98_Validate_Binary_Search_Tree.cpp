#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//前序输入二叉树
TreeNode* frontWrite(vector<int> v, int &pos)
{
	++pos;
	TreeNode* t;
	if ((unsigned)pos >= v.size())
		return NULL;
	else
	{
		if (v[pos] == NULL)
			t = NULL;
		else
		{
			t = new TreeNode(v[pos]); //这里的 new 好像很有门道
			t->left = frontWrite(v, pos);
			t->right = frontWrite(v, pos);
		}
		return t;
	}
}

TreeNode* frontWrite(vector<int> v)
{
	int pos = -1;
	TreeNode* root = frontWrite(v, pos);
	return root;
}
//前序遍历二叉树
void frontRead(TreeNode* root)
{
	if (root != NULL)
	{
	
	cout << root->val << "	";
	frontRead(root->left);
	frontRead(root->right);
	}
}

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, NULL, NULL);
	}
	bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max)
	{
		if (!root)
			return true;
		if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val))
			return false;
		return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
	}

};
void main_Validate_Binary_Search_Tree()
{
	vector<int> v = { 2,1,NULL,NULL,3 };
	int pos = -1;
	TreeNode* root = frontWrite(v, pos);
	frontRead(root);


	Solution so;
	cout << so.isValidBST(root) << endl;
	system("pause");
}