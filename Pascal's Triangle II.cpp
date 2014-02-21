class Solution {
public:
    vector<int> getRow(int rowIndex){
	vector<int> res = { 1 };
	for (int i = 1; i <= rowIndex; i++)
	{
		int end = res.size();
		vector<int> tmp = res;
		res.clear();
		for (int j = 0; j <= end; j++)
		{
			if (j == 0 || j == end) res.push_back(1);
			else
			{
				res.push_back(tmp[j-1] + tmp[j]);
			}
		}
	}
	return res;
}
};