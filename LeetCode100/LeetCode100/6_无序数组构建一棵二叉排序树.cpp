#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void funcCore(vector<int> nums, int i, TreeNode* root)
{
	if (i == nums.size())
		return;
	
	else if (nums[i] < root->val)
	{
		if (root->left == NULL)
			root->left = new TreeNode(nums[i]);
		else
			funcCore(nums, i, root->left);

	}
	else
	{
		if (root->right == NULL)
			root->right = new TreeNode(nums[i]);
		else
			funcCore(nums, i, root->right);
	}
	
}

TreeNode* func(vector<int> nums)
{
	if (nums.size() == 0)
		return NULL;
	TreeNode* root = new TreeNode(nums[0]);
	for(int i = 1;i < nums.size();++i)
		funcCore(nums, i, root);

	
	return root;
}


void print(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << endl;
	print(root->left);
	print(root->right);
}
int main()
{
	vector<int> nums = { 10,8,9,6,12,11,13 };
	TreeNode* root = func(nums);
	print(root);
	system("pause");
	return 0;
}