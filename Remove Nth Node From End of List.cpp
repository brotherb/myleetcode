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

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == NULL)return NULL;
    ListNode *p = head;
    while (n--){
        p = p->next;
    }

    if(p == NULL)return head->next;
    ListNode *h = head;
    ListNode *q = head->next;
    p = p->next;
    while (p){
        p = p->next;
        q = q->next;
        h = h->next;
    }
    h->next = q->next;
    return head;
}

int main(int argc, const char * argv[])
{

    ListNode *head = new ListNode(1);
//    for (int i = 6;i>1;i--){
//        ListNode *p = new ListNode(i);
//
//        p->next = head->next;
//        head->next = p;
//    }
    ListNode *p = head;
    while (p){
        printf("%d ", p->val);
        p = p->next;
    }
    putchar('\n');
    ListNode *res = removeNthFromEnd(head,1);
    p =res;
    while (p){
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}
