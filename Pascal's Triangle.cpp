class Solution {
public:
    vector<vector<int> > generate(int numRows) {
	if(numRows <= 0) return {};
	vector<vector<int>> res = { { 1 } };
	if (numRows == 1) return res;
	for (int i = 1; i < numRows; i++)
	{
		vector<int> line;
		int end = res[i - 1].size();
		for (int j = 0; j <= end; j++)
		{
			if (j == 0 || j == end) line.push_back(1);
			else
			{
				line.push_back(res[i - 1][j-1] + res[i - 1][j]);
			}
		}
		res.push_back(line);
	}
	return res;
}
};