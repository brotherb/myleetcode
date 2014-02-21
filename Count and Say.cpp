class Solution {
public:
    string countAndSay(int n) {
    	// IMPORTANT: Please reset any member data you declared, as
    	// the same Solution instance will be reused for each test case.
    	string st = "1";
    	string res;
    	if (n == 1)return "1";
    	while (--n)
    	{
    		int count = 0;
    		int cur = st[0];
    		char c[3] = "";
    		res = "";
    		for (int i = 0; i < st.length(); i++)
    		{
    			if (st[i] != cur)
    			{
    				c[0] = count + '0';
    				c[1] = cur;
    				res.append(c);
    				cur = st[i];
    				count = 1;
    			}
    			else
    			{
    				count++;
    			}
    		}
    		c[0] = count + '0';
    		c[1] = cur;
    		res.append(c);
    		st = res;
    	}
    	return res;
    }
};
