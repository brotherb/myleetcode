class Solution {
public:
    int removeDuplicates(int A[], int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (n < 2)return n;
		int i = 0, j = 1;
		int end = 0;
		while (j < n)
		{
			while (A[i] == A[j])
			{
				j++;
				if (j == n)
				{
					end = 1;
					break;
				}
			}
			if (end) break;
			if (j - i > 1)
			{
				A[i + 1] = A[j];
			}
			i++;
			j++;
		}
		return i+1;
	}
};