//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *swapPairs(ListNode *head) {
    if (head == NULL)return NULL;
    if (head->next == NULL)return head;
    ListNode *p = head, *q = head->next;
    p->next = q->next;
    q->next = p;
    head = q;
    while(1){
        q = p->next;
        if(q == NULL)return head;
        q = q->next;
        if(q == NULL)return head;
        p->next->next = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
    }
}


int main(int argc, const char * argv[])
{

    ListNode *head = new ListNode(1);
    for (int i = 1;i>1;i--){
        ListNode *p = new ListNode(i);

        p->next = head->next;
        head->next = p;
    }
    ListNode *p = head;
    while (p){
        printf("%d ", p->val);
        p = p->next;
    }
    putchar('\n');
    ListNode *res = swapPairs(head);
    p =res;
    while (p){
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}
