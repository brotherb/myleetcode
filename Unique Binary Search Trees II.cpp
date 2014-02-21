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

vector<TreeNode *> _generateTrees(vector<int> &range){
    vector<TreeNode *> res(0);
    int len = range.size();
    if(len == 0){
        res.push_back(NULL);
        return res;
    }
    for (int i = 0; i < len; i++) {
        vector<int> left(range.begin(),range.begin()+i);
        vector<int> right(range.begin()+i+1,range.end());

        vector<TreeNode *> leftTrees = _generateTrees(left);
        vector<TreeNode *> rightTrees = _generateTrees(right);

        for (int j = 0; j < leftTrees.size(); j++){
            for (int k = 0; k < rightTrees.size(); k++){
                TreeNode *root = new TreeNode(range[i]);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n) {
    vector<int> range(0);
    for (int i = 0; i < n; i++){
        range.push_back(i+1);
    }
    return _generateTrees(range);
}

int main(int argc, const char * argv[])
{
    vector<int> a = {1,2,3};
    vector<TreeNode *> res = _generateTrees(a);

    cout<<res.size()<<endl;
    return 0;
}
