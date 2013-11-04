class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int lo = 0, hi = n - 1;
		while (lo<=hi)
		{
			while (A[lo]!=elem)
			{
				lo++;
				if (lo > hi)goto end;
			}
			while (A[hi]==elem)
			{
				hi--;
				if (lo > hi)goto end;
			}
			A[lo] = A[hi];
			hi--;
		}
	end:	return hi+1;
	}
};