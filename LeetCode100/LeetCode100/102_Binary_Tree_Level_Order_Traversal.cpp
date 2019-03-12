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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		vector<TreeNode*> up;
		up.push_back(root);
		while (!up.empty())
		{
			vector<TreeNode*> down;
			vector<int> cur;
			for (vector<TreeNode*>::iterator it = up.begin(); it != up.end(); ++it)
			{
				cur.push_back((*it)->val);
				if ((*it)->left != NULL)
					down.push_back((*it)->left);
				if ((*it)->right != NULL)
					down.push_back((*it)->right);
			}
			res.push_back(cur);
			up = down;
		}
		return res;
	}
};