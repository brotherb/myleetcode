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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!p&&!q)return true;
        else if (p&&!q || !p&&q)return false;
        else if(p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        else return false;
    }
};