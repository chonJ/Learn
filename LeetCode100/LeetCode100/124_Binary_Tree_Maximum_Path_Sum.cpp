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
	//没考虑清楚 题意是一支
	int maxPathSum_my(TreeNode* root)
	{
		if (root == NULL)
			return INT_MIN;
		int l = maxPathSum_my(root->left);
		int r = maxPathSum_my(root->right);
		if (l == INT_MIN && r == INT_MIN)
			return  maxf(root->val, root->val, root->val, root->val, l, r);
		else if (l == INT_MIN)
			return maxf(root->val, root->val, root->val + r * (int)flagr, root->val, l, r);
		else if (r == INT_MIN)
			return maxf(root->val, root->val + l * (int)flagl, root->val, root->val, l, r);
		else
			return maxf(root->val, root->val + l * (int)flagl, root->val + r * (int)flagr, root->val + l * (int)flagl + r * (int)flagr,l,r);
	}
	int maxf(int a, int b, int c, int d,int e,int f)
	{
		//int max = a;
		//cout << a << b << endl;
		flagl = true;
		flagr = true;

		if (b > a)	a = b;
		cout << a << endl;
		if (c > a)	a = c;
		if (d > a)	a = d;
		if (e > a) {
			a = e; flagl = false;
		}
		if (f > a) {
			a = f; flagr = false;
		}
		return a ;
	}
private:

	bool flagl = true;
	bool flagr = true;

	//正确解法   一定要 1 理解题意 2 想清楚思路 3 写代码
public:
	int maxPathSum(TreeNode* root)
	{
		max = INT_MIN;
		maxPathDown(root);
		return max;
	}
private:
	int max;
	int maxPathDown(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int l = maxPathDown(root->left);
		int r = maxPathDown(root->right);
		int left = l > 0 ? l : 0;
		int right = r > 0 ? r : 0;
		max = max > (left + right + root->val) ? max : (left + right + root->val);
		cout << max << endl;
		return root->val + (left > right ? left : right);
	}
};


void prePrint(TreeNode* root);


void main_Binary_Tree_Maximum_Path_Sum()
{
	Solution so;
	vector<int> v = {3,-2};
	TreeNode* root = preCreatTree(v);
	//int a = INT_MIN;
	//int b = -3;
	//cout <<( a < b) << endl;
	//prePrint(root);
	

	cout << so.maxPathSum(root) << endl;
	system("pause");
}