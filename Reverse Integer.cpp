class Solution {
public:
    int reverse(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int N=0;
        while(x!=0)
        {
            N*=10;
            N+=x%10;
            x/=10;
        }
        return N;
    }
};