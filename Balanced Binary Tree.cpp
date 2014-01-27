//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int Dep(TreeNode *root){
    if(root == NULL)return 0;
    root->val = max(Dep(root->left), Dep(root->right)) + 1;
    return root->val;
}

bool _isBalanced(TreeNode *root){
    if(root==NULL||(root->left==NULL && root->right==NULL))return true;
    if(_isBalanced(root->left) && _isBalanced(root->right)){
        if(root->left == NULL)return (root->right->val==1);
        if(root->right == NULL)return (root->left->val==1);
        return (abs(root->left->val - root->right->val)<=1);
    }
    return false;
}

bool isBalanced(TreeNode *root) {
    Dep(root);
    return _isBalanced(root);
}

int main(int argc, const char * argv[])
{
    TreeNode *p = new TreeNode(0);
    TreeNode *q = new TreeNode(0);
    TreeNode *k = new TreeNode(0);
    TreeNode *i = new TreeNode(0);
    TreeNode *j = new TreeNode(0);
    cout<< isBalanced(p)<<endl;

    p->left = q;
    cout<< isBalanced(p)<<endl;
    q->left = k;
    cout<< isBalanced(p)<<endl;
    p->right = i;
    cout<< isBalanced(p)<<endl;
    k->right = i;
    cout<< isBalanced(p)<<endl;
    return 0;
}
