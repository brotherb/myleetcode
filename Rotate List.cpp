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
    ListNode *rotateRight(ListNode *head, int k) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if(head == NULL) return NULL;
	int len = 0;
	ListNode *p = head, *q, *res;
	while (p)
	{
		len++;
		p = p->next;
	}
	k %= len;
	if (k == 0) return head;
	int count = len - k;
	p = head;
	while (--count)
	{
		p = p->next;
	}
	res = p->next;
	count = len;
	q = head;
	while (--count)
	{
		q = q->next;
	}
	p->next = NULL;
	q->next = head;
	return res;
}
};