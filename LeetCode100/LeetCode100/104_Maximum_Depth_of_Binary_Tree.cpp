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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		//  递归一定要避免这种多次递归写法
		//return 1 + (maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) : maxDepth(root->right));

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return 1 + (left > right ? left : right);
	}


};




void main_Maximum_Depth_of_Binary_Tree()
{
	vector<int> v = {3,9,-1,-1,20,15,-1,-1,7 };
	TreeNode* root = preCreatTree(v);
	//prePrint(root);
	Solution so;
	cout << so.maxDepth(root) << endl;
	system("pause");
}