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

TreeNode *sortedArrayToBST(vector<int> &num) {
    if (num.size() == 0)return NULL;
    int mid = num.size()/2;
    vector<int> left, right;
    left.assign(num.begin(), num.begin()+mid);
    right.assign(num.begin()+mid+1, num.end());
    TreeNode *root = new TreeNode(num[mid]);
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}

int main(int argc, const char * argv[])
{
    vector<int> a ={1,2};
    TreeNode *p = sortedArrayToBST(a);

    return 0;
}
