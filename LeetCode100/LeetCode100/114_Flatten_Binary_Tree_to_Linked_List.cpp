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
	void flatten(TreeNode* root) {
		while(root)
		{
			if (root->left && root->right)
		{
			TreeNode* t = root->left;
			/*while (t)
				t = t->right;
			t = root->right;*/    //写法不对最后t为空值 注意最后的复制应为 向（非空）->right 赋值   而不能 向 NULL 赋值
			while (t->right)
				t = t->right;
			t->right = root->right;
		}
			if (root->left)
			root->right = root->left;

			root->left = NULL;			
			root = root->right;
		}
	}
};

void prePrint(TreeNode* root);


void main_Flatten_Binary_Tree_to_Linked_List()
{
	vector<int> v = { 1,2,3,-1,-1,4,-1,-1,5,-1,6 };
	vector<int> u = { 9,3,15,20,7 };
	Solution so;

	TreeNode* root = preCreatTree(v);
	so.flatten(root);
	
	prePrint(root);

	system("pause");
}