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

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res(0);
    if(root == NULL) return res;

    res.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

int main(int argc, const char * argv[])
{
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(2);
    TreeNode *i = new TreeNode(3);
    TreeNode *j = new TreeNode(0);
    p->right = q;
    q->left = i;
    vector<int> res = preorderTraversal(p);
    for (int i = 0; i < res.size(); i++){
        printf("%2d",res[i]);
    }
    return 0;
}
