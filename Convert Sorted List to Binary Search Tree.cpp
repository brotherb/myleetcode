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

TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL)return NULL;
    if (head->next == NULL)return new TreeNode(head->val);

    ListNode *slow = head;
    ListNode *fast = head;

    while (1){
        if (fast->next->next!= NULL){
            fast = fast->next;
            if(fast->next->next!=NULL){
                fast = fast->next;
                slow = slow->next;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    TreeNode *root = new TreeNode(slow->next->val);
    root->right = sortedListToBST(slow->next->next);
    slow->next = NULL;
    root->left = sortedListToBST(head);
    return root;
}

int main(int argc, const char * argv[])
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    TreeNode *p = sortedListToBST(root);

    return 0;
}
