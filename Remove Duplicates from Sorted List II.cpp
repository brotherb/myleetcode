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
	if (head == NULL) return head;
	ListNode *st = head, *hook = head;
	int flag;
	while (st)
	{
		ListNode *p = st, *q = p->next;
		flag = 0;
		while (q)
		{
			if (q->val == st->val)
			{
				p->next = q->next;
				q = q->next;
				flag = 1;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		if (flag)
		{
			if (st == head)
			{
				head = head->next;
				st = head;
				hook = st;
			}
			else
			{
				hook->next = st->next;
				st = st->next;
			}
		}
		else
		{
			if (hook->next == st)
				hook = hook->next;
			st = st->next;
		}
	}
	return head;
}
};