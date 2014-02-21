class Solution {
public:
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *res = NULL;
	ListNode *f, *p;
	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	else if (l1 == NULL)
	{
		res = new ListNode(l2->val);
		l2 = l2->next;
	}
	else if (l2 == NULL)
	{
		res = new ListNode(l1->val);
		l1 = l1->next;
	}
	else
	{
		int val = l1->val < l2->val ? l1->val : l2->val;
		if (l1->val < l2->val)
			l1 = l1->next;
		else
			l2 = l2->next;
		res = new ListNode(val);
	}
	f = res;
	while (l1&&l2)
	{
		int val = l1->val < l2->val ? l1->val : l2->val;
		if (l1->val < l2->val)
			l1 = l1->next;
		else
			l2 = l2->next;
		f->next = new ListNode(val);
		f = f->next;
	}
	while (l1)
	{
		f->next = new ListNode(l1->val);
		f = f->next;
		l1 = l1->next;
	}
	while (l2)
	{
		f->next = new ListNode(l2->val);
		f = f->next;
		l2 = l2->next;
	}
	return res;
}
};