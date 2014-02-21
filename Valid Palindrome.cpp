class Solution {
public:
    bool isPalindrome(string s) {
    int len = s.length();
    if(len == 0) return true;
    string c(len, 0);
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if(!isalnum(s[i]))continue;
        c[j++] = tolower(s[i]);
    }
    for(int lo = 0, hi = j-1;lo<=hi;lo++, hi--)
    {
        if(c[lo]!=c[hi])return false;
    }
    return true;
}
};