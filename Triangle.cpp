class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int rows = triangle.size();
		if (rows == 1) return triangle[0][0];
		vector<int> path(triangle[rows-1]);
		for (int i = rows-2; i >=0; i--)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				path[j] = triangle[i][j] + min(path[j], path[j + 1]);
			}
		}
		return path[0];
	}
};