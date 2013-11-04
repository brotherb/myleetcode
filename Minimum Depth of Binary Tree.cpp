/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int minDepth(TreeNode *root) {
		if (!root)return 0;
		int lenl = minDepth(root->left);
		int lenr = minDepth(root->right);
		if (lenl && lenr)
			return min(lenl, lenr)+1;
		else
		{
			if (lenl == 0) return lenr + 1;
			else return lenl + 1;
		}
	}
};