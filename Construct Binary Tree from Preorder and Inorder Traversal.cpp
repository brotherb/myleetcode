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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.size() == 0)return NULL;
    int mid = preorder[0];
    vector<int>::iterator pos = find(inorder.begin(), inorder.end(), mid);
    TreeNode *root = new TreeNode(mid);
    preorder.erase(preorder.begin());
    vector<int> inorder_left(inorder.begin(),pos);
    vector<int> inorder_right(pos+1,inorder.end());
    root->left = buildTree(preorder, inorder_left);
    root->right = buildTree(preorder, inorder_right);
    return root;
}

int main(int argc, const char * argv[])
{
    vector<int> a = {1,2,4,5,3,6,7};
    vector<int> b = {4,2,5,1,6,3,7};
    TreeNode *p = buildTree(a, b);
    return 0;
}
