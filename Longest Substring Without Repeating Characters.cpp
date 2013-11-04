class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int len = s.length();
		if (len < 2)return len;

		string::iterator beg = s.begin();

		int cur=0, longest=0;
		for (string::iterator it = s.begin() + 1; it != s.end(); ++it)
		{
			string::iterator res = find(beg, it, *it);
			if (res != it)
			{
				 cur = it - beg;
				 if (cur > longest)
					 longest = cur;
				 beg = res + 1;
			}
		}
		cur = s.end() - beg;
		if (cur > longest)
			longest = cur;
		return longest;
	}

};