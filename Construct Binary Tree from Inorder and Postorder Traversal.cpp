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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0)return NULL;
    int mid = postorder.back();
    vector<int>::iterator pos = find(inorder.begin(), inorder.end(), mid);
    TreeNode *root = new TreeNode(mid);
    postorder.pop_back();
    vector<int> inorder_left(inorder.begin(),pos);
    vector<int> inorder_right(pos+1,inorder.end());
    root->right = buildTree(inorder_right,postorder);
    root->left = buildTree(inorder_left,postorder);
    return root;
}

int main(int argc, const char * argv[])
{
    vector<int> b = {4,5,2,6,7,3,1};
    vector<int> a = {4,2,5,1,6,3,7};
    TreeNode *p = buildTree(a, b);
    return 0;
}
