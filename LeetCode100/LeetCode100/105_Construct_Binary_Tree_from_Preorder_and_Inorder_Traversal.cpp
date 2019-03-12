#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
TreeNode* preCreatTree(vector<int> v, int &pos);


TreeNode* preCreatTree(vector<int> v);


class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//TreeNode* root = NULL;
		//if (preorder.size() == 0 || preorder.size() != inorder.size())
		//	return root;
		//return root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
		return  buildTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright)
	{
		TreeNode* t = NULL;
		if ( preleft > preright)
			return  t;
		cout << preorder[preleft] <<endl;
		t = new TreeNode(preorder[preleft]);
		if (preleft == preright)
			return t;
		int i;
		for (i = 0; inorder[inleft + i] != preorder[preleft]; ++i);//for是初始化，先判断 在执行函数体 然后++ 再判断循环
		t->left = buildTree(preorder, inorder, preleft + 1, preleft + i, inleft, inleft + i - 1);
		t->right = buildTree(preorder, inorder, preleft + i + 1, preright, inleft + i + 1, inright);
		return t;
	}


};

void prePrint(TreeNode* root);


void main_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal()
{
	vector<int> v = { 3,9,20,15,7 };
	vector<int> u = { 9,3,15,20,7 };
	Solution so;
	
	TreeNode* root = so.buildTree(v, u);
	prePrint(root);
	
	system("pause");
}