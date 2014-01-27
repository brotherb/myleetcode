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

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res(0);
    if(root == NULL) return res;
    vector<int> left = inorderTraversal(root->left);
    vector<int> right = inorderTraversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(root->val);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

int main(int argc, const char * argv[])
{
    vector<int> b = {4,5,2,6,7,3,1};
    vector<int> a = {4,2,5,1,6,3,7};
//    TreeNode *p = buildTree(a, b);
    return 0;
}
