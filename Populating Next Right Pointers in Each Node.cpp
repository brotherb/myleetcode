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


struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


void connect(TreeLinkNode *root) {
    if(root == NULL)return;
    TreeLinkNode *head = root->left;
    TreeLinkNode *p = root, *q = p->next;
    while (head){
        while (q){
            p->left->next = p->right;
            p->right->next = q->left;
            p = p->next;
            q = q->next;
        }
        p->left->next = p->right;
        p = head;
        q = p->next;
        head = head->left;
    }
    return;
}

int main(int argc, const char * argv[])
{
    TreeLinkNode *p = new TreeLinkNode(1);
    TreeLinkNode *i = new TreeLinkNode(2);
    TreeLinkNode *j = new TreeLinkNode(3);
    p->left = i;
    p->right = j;
    connect(p);
    return 0;
}
