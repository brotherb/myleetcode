//the point is where the target should be if the target is not in the list
class Solution {
public:
int searchInsert(int A[], int n, int target) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	int lo = 0, hi = n - 1;
	int mid;
	while(lo<=hi)
	{
		mid = (lo + hi) / 2;
		if (A[mid] == target)
		{
			return mid;
		}
		else if (A[mid] < target)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	return lo;
}
};