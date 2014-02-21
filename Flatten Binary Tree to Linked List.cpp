//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#include <assert.h>
#import <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void flatten(TreeNode *root) {
    if (root == NULL || root->right == NULL && root->left == NULL)return;
    if (root->left == NULL){
        flatten(root->right);
        return;
    }
    if (root->right == NULL){
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
        return;
    }
    flatten(root->left);
    flatten(root->right);
    TreeNode *p = root->left;
    while (p->right){
        p = p->right;
    }
    p->right = root->right;
    root->right = root->left;
    root->left = NULL;
}

int main(int argc, const char * argv[])
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->right = new TreeNode(6);
    flatten(p);
    return 0;
}
