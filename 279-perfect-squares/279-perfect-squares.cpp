class Solution {
public:
    int f(int n,int ind,vector<vector<int>>& dp)
    {
        if(n==0)
            return 0;
        if(n<0 || (ind*ind)>n)
            return 1e9;
        if(dp[n][ind]!=-1) return dp[n][ind];
        int nottake=f(n,ind+1,dp);
        int take=1e9;
        if((ind*ind)<=n)
            take=1+f(n-(ind*ind),ind,dp);
        return dp[n][ind]=min(take,nottake);
    }
    int numSquares(int n) {
        vector<vector<int>> dp(n+1,vector<int>(101,-1));
        return f(n,1,dp);  
    }
};