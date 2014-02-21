class Solution {
public:
    string longestPalindrome(string s) {
    	string res;
    	int len = s.length();
    	int maxleft = 0;
    	int maxright = 0;
    	int maxlen = 0;
    	for (size_t i = 0; i < len; i++)
    	{
    		int mid = i;
    		int left = mid - 1;
    		int right = mid + 1;
    		int tmplen = 1;
    		while (left>=0&&right<len)
    		{
    			if (s[left] == s[right]){
    				tmplen += 2;
    				left--;
    				right++;
    			}
    			else{
    				break;
    			}
    		}
    		if (maxlen < tmplen){
    			maxleft = left+1;
    			maxright = right-1;
    			maxlen = tmplen;
    		}
    
    		tmplen = 0;
    		left = mid;
    		right = mid + 1;
    		while (left >= 0 && right<len)
    		{
    			if (s[left] == s[right]){
    				tmplen += 2;
    				left--;
    				right++;
    			}
    			else{
    				break;
    			}
    		}
    		if (maxlen < tmplen){
    			maxleft = left + 1;
    			maxright = right - 1;
    			maxlen = tmplen;
    		}
    	}
    	res = s.substr(maxleft, (maxright - maxleft + 1));
    	return res;
    }
};