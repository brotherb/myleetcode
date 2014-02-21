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

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > res(0);
    if(root == NULL)return res;
    vector<vector<int> > left = levelOrder(root->left);
    vector<vector<int> > right = levelOrder(root->right);
    vector<int> cur(1, root->val);
    res.push_back(cur);
    int i;
    for (i = 0; i < min(left.size(), right.size()); i++){
        left[i].insert(left[i].end(), right[i].begin(), right[i].end());
        res.push_back(left[i]);
    }
    while (i < left.size()){
        res.push_back(left[i]);
        i++;
    }
    while (i <right.size()){
        res.push_back(right[i]);
        i++;
    }

    return res;
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > res = levelOrder(root);
    for (int i = 0; i < res.size(); i++){
        if(i%2){
            reverse(res[i].begin(), res[i].end());
        }
    }
    return res;
}

int main(int argc, const char * argv[])
{
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);

    vector<vector<int> > res = zigzagLevelOrder(p);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            printf("%d ",res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
