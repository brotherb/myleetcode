/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head==NULL)return head;
        ListNode *q = head, *p = q->next;
        int cur = q->val;
        while(p)
        {
            if(p->val == cur)
            {
                p = p->next;
                q->next = p;
            }
            else
            {
                q = p;
                cur = p->val;
                p = p->next;
            }
        }
        return head;
    }
};