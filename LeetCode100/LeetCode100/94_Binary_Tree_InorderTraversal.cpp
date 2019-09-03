#include<iostream>
#include<vector>

using namespace std;


 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if(root != NULL) inorder(root,res );
		return res;
	}
	void inorder(TreeNode* root, vector<int>& res)
	{
		if (root->left == NULL && root->right == NULL)
		{
			res.push_back(root->val);
			return;
		}
		if (root->left != NULL)
		{
			inorder(root->left, res);
				res.push_back(root->val);
		}
		if (root->right != NULL)
		{
			inorder(root->right, res);

		}

	}
};

void main94_Binary_Tree_InorderTraversal()
{

}