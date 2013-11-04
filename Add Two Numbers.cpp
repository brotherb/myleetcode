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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		ListNode *res = NULL;
		ListNode *p = NULL;
		ListNode *q = NULL;
		int flag = 0;
		while (l1&&l2)
		{
			int sum = l1->val + l2->val + flag;
			if (sum >= 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			if (res == NULL)
			{
				res = new ListNode(sum);
				p = res;
			}
			else
			{
				q = new ListNode(sum);
				p->next = q;
				p = p->next;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			int sum = l1->val + flag;
			if (sum == 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			q = new ListNode(sum);
			p->next = q;
			p = q;
			l1 = l1->next;
		}
		while (l2)
		{
			int sum = l2->val + flag;
			if (sum == 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			q = new ListNode(sum);
			p->next = q;
			p = q;
			l2 = l2->next;
		}
		if (flag != 0)
		{
			q = new ListNode(flag);
			p->next = q;
		}
		return res;
	}
};