//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#include <assert.h>

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

bool Greater(TreeNode *root, int target){
    if(root == NULL)return true;
    return Greater(root->left, target) && Greater(root->right, target) && root->val > target;
}

bool Smaller(TreeNode *root, int target){
    if(root == NULL)return true;
    return Smaller(root->left, target) && Smaller(root->right, target) && root->val < target;
}

bool isValidBST(TreeNode *root) {
    if(root == NULL)return true;
    if(root->left == NULL && root->right == NULL)return true;
    if(root->left == NULL)return (Greater(root->right, root->val) && isValidBST(root->right));
    if(root->right == NULL)return (Smaller(root->left, root->val) && isValidBST(root->left));
    return isValidBST(root->right) && isValidBST(root->left)
            && (Smaller(root->left, root->val)) && (Greater(root->right, root->val));
}

int main(int argc, const char * argv[])
{
    TreeNode *head = new TreeNode(10);
    assert(isValidBST(head) == true);
    head->left = new TreeNode(5);
    assert(isValidBST(head) == true);
    head->right = new TreeNode(15);
    assert(isValidBST(head) == true);
    head->right->left = new TreeNode(6);
    assert(isValidBST(head) == true);
    head->right->right = new TreeNode(20);
    assert(isValidBST(head) == false);
    return 0;
}
