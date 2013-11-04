class Solution {
public:
    int maxProfit(vector<int> &prices) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if (prices.size() == 0) return 0;
	int max = 0, lowest = prices[0];
	int cur;
	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < lowest) lowest = prices[i];
		cur = prices[i] - lowest;
		if (cur > max) max = cur;
	}
	return max;
}
};