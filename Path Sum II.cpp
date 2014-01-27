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

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > res(0);
    if(root == NULL) return res;
    if(root->left == NULL && root->right == NULL){
        if(root->val == sum) {
            vector<int> a(0);
            a.push_back(sum);
            res.push_back(a);
            return res;
        }
        return res;
    }
    else{
        vector<vector<int> > left = pathSum(root->left, sum-root->val);
        vector<vector<int> > right = pathSum(root->right, sum-root->val);

        for (int i = 0; i < left.size(); i++){
            left[i].insert(left[i].begin(), root->val);
        }
        for (int i = 0; i < right.size(); i++){
            right[i].insert(right[i].begin(), root->val);
        }
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
}

int main(int argc, const char * argv[])
{
    TreeNode *p = new TreeNode(5);
    TreeNode *left = new TreeNode(4);
    TreeNode *right = new TreeNode(8);
    p->left = left;
    p->right = right;
    left = new TreeNode(11);
    p->left->left = left;
    left = new TreeNode(7);
    right = new TreeNode(2);
    p->left->left->left = left;
    p->left->left->right = right;

    left = new TreeNode(13);
    right = new TreeNode(4);
    p->right->left = left;
    p->right->right = right;

    left = new TreeNode(5);
    right = new TreeNode(1);
    p->right->right->left = left;
    p->right->right->right = right;


    vector<vector<int> > res = pathSum(p, 22);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            printf("%3d", res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
