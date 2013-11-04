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
    bool find(ListNode *cur, ListNode *head)
	{
		ListNode *p = head;
		while (p!=cur->next)
		{
			if (p == cur)
				return false;
			p = p->next;
		}
		return true;
	}

	ListNode *detectCycle(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (!head) return NULL;
		ListNode *cur = head;
		while (cur)
		{
			if (find(cur, head))
				return cur->next;
			cur = cur->next;
		}
		return NULL;
	}
};