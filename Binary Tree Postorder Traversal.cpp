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

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res(0);
    if (root == NULL)return res;
    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(root->val);
    return res;
}

int main(int argc, const char * argv[])
{
    int a[3] ={1,3,5};
    int b[1] = {};
    merge(a, 3, b, 0);
    return 0;
}
