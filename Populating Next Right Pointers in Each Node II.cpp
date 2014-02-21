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

TreeLinkNode *findNextOneWithChild(TreeLinkNode *next){
    while (next){
        if(!(next->left || next->right)){
            next = next->next;
        }else{
            return next;
        }
    }
    return NULL;
}

void connect(TreeLinkNode *root) {
    if(root == NULL)return;
    TreeLinkNode *head = NULL;
    if(root->left){
        head = root->left;
    }else{
        head = root->right;
    }
    TreeLinkNode *s = head;
    TreeLinkNode *p = root, *q = NULL;
    while (head){
        while (q){
            if (p->left == s){
                if(p->right){
                    s->next = p->right;
                    s = s->next;
                }
            }

            if(q->left){
                s->next = q->left;
                s = s->next;
            }else{
                s->next = q->right;
                s = s->next;
            }
            p = q;
            q = findNextOneWithChild(q->next);
        }
        if(p->left)
            p->left->next = p->right;
        p = findNextOneWithChild(head);
        if(p == NULL)
            return;
        if(p->left)head = p->left;
        else head = p->right;
        s = head;
        q = findNextOneWithChild(p->next);
    }
}

int main(int argc, const char * argv[])
{
    TreeLinkNode *p = new TreeLinkNode(1);
    TreeLinkNode *i = new TreeLinkNode(2);
    TreeLinkNode *j = new TreeLinkNode(3);
    TreeLinkNode *k = new TreeLinkNode(5);
    TreeLinkNode *l = new TreeLinkNode(4);
//    p->left = i;
//    p->right = j;
//    j->right = k;
//    i->left = l;
    connect(p);
    return 0;
}
