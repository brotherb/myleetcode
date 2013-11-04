class Solution {
public:
    int maxProfit(vector<int> &prices) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (prices.size() < 2) return 0;
		int max, min;
		max = prices[0];
		min = prices[0];
		int sum = 0;
		int n = prices.size();
		for (int i = 1; i < n; i++)
		{
			if (prices[i] == max)continue;
			if (prices[i] > max)
			{
				max = prices[i];
			}
			if (prices[i] < max)
			{
				sum += max - min;
				min = prices[i];
				max = prices[i];
			}
		}
		sum += max - min;
		return sum;
	}
};