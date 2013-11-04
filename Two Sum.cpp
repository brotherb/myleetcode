class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        vector<int>::iterator it;
        vector<int>::iterator flag;
        for(it = numbers.begin(); it != numbers.end(); ++it)
        {
            flag = find(it+1, numbers.end(), target - *it);
            if(flag!=numbers.end())
            {
                res.push_back(it-numbers.begin()+1);
                res.push_back(flag-numbers.begin()+1);
            }
        }
        return res;
    }
};