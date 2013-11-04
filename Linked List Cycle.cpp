//very good idea without extra memory. Using a list to store node and check if the current node is already in the list will cause time exceeding.
class Solution {
public:
	bool hasCycle(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		ListNode *a = head, *b = head;
		if(head==NULL)return false;
		do
		{
			if(a->next!=NULL)
			    a = a->next;
			if(a->next!=NULL)
			    a = a->next;
			else
			    return false;
			if(b->next!=NULL)
			    b = b->next;
		}while(a!=b);
		return true;
	}
};