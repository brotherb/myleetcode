class Solution {
public:
    bool isPalindrome(int x) {
    	// IMPORTANT: Please reset any member data you declared, as
    	// the same Solution instance will be reused for each test case.
    	if (x == 0) return true;
    	if (x < 0) return false;
    	int a[10] = { 0 };
    	int i = 0;
    	while (x!=0)
    	{
    		a[i] = x % 10;
    		x = x / 10;
    		i++;
    	}
    	for (int lo = 0, hi = i-1; lo <= hi; ++lo, --hi)
    		if (a[lo] != a[hi])
    			return false;
    	return true;
    }
};