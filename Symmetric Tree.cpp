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
bool isMirror(TreeNode *p, TreeNode *q){
    if(!p&&!q)return true;
    if((p&&!q)||(!p&&q))return false;
    if(isMirror(p->left, q->right) && isMirror(p->right, q->left)){
        return p->val == q->val;
    }
    return false;
}

bool isSymmetric(TreeNode *root) {
    if(root==NULL)return true;
    return isMirror(root->left, root->right);
}

int main(int argc, const char * argv[])
{
    TreeNode *p = new TreeNode(0);
    TreeNode *q = new TreeNode(0);
    TreeNode *j = new TreeNode(0);
    TreeNode *k = new TreeNode(0);
    TreeNode *i = new TreeNode(0);
    TreeNode *s = new TreeNode(0);
    TreeNode *w = new TreeNode(0);
    cout<< isSymmetric(p)<<endl;
    p->left = q;
    cout<< isSymmetric(p)<<endl;
    p->right = j;
    cout<< isSymmetric(p)<<endl;
    j->val = 1;
    cout<< isSymmetric(p)<<endl;
    j->val = 0;
    q->left = k;
    q->right = i;
    j->left = s;
    j->right = w;
    cout<< isSymmetric(p)<<endl;
    k->val = 1;
    cout<< isSymmetric(p)<<endl;
    w->val = 1;
    cout<< isSymmetric(p)<<endl;

    return 0;
}
