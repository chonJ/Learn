#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		preOrder(root);
		return back(root);
	}
	void preOrder(TreeNode* root)
	{
		if (root == NULL)
		{
			q.push(-1);
			return;
		}
		else
		{
			q.push(root->val);
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	bool back(TreeNode* root)
	{
		
		if (root == NULL)
			if (q.empty())
				return true;
			else if (q.front() == -1)
			{
				q.pop(); return true;
			}
			else
				return false;
		else if (!q.empty() && q.front() == root->val)
		{
			q.pop();
			return back(root->right) && back(root->left);
		}
		else
			return false;
	}
private:
	queue<int> q;
};

TreeNode* preCreatTree(vector<int> v,int &pos)
{
	pos++;
	TreeNode* t;
	if ((unsigned)pos >= v.size())
		return NULL;
	else
	{
		if (v[pos] == -1)
			t = NULL;
		else
		{
			t = new TreeNode(v[pos]);
			t->left = preCreatTree(v, pos);
			t->right = preCreatTree(v, pos);
		}
	}
	return t;
}

TreeNode* preCreatTree(vector<int> v)
{
	int pos = -1;
	TreeNode* root = preCreatTree(v, pos);
	return root;
}

void prePrint(TreeNode* root)
{
	if (root != NULL)
	{
		cout << root->val << "	";
		prePrint(root->left);
		prePrint(root->right);
	}
}
void main_Symmetric_Tree()
{
	vector<int> v = {1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3};
	TreeNode* root = preCreatTree(v);
	//prePrint(root);
	Solution so;
	cout << so.isSymmetric(root) << endl;
	system("pause");
}