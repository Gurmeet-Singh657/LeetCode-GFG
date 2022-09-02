class Solution {
public:
    int numSquares(int n) {
        if(n==0 || n==1) return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                int curr=i-(j*j);
                if(dp[curr]+1<mini)
                    mini=1+dp[curr];
            }
            dp[i]=mini;
        }
        return dp[n];  
    }
};