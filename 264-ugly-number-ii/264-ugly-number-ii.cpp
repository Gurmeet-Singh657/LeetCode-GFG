class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1]=1; // first ugly number
        int ptr2=1,ptr3=1,ptr5=1;
        for(int i=2;i<=n;i++)
        {
            int curr2=2*dp[ptr2];
            int curr3=3*dp[ptr3];
            int curr5=5*dp[ptr5];
            int mini=min(curr2,min(curr3,curr5));
            dp[i]=mini;
            if(curr2==mini)
                ptr2++;
            if(curr3==mini)
                ptr3++;
            if(curr5==mini)
                ptr5++;
        }
        return dp[n];
    }
};