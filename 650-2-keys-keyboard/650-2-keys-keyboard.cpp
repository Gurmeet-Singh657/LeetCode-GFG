class Solution {
public:
    int f(int curr,int n,int count,vector<vector<int>>& dp)
    {
        if(count==n)
            return 0;
        if(count>n)
            return 1e9;
        if(dp[curr][count]!=-1) return dp[curr][count];
        int firstway=1+f(curr,n,count+curr,dp);
        int secondway=2+f(count,n,count+count,dp);
        return dp[curr][count]=min(firstway,secondway);
    }
    int minSteps(int n) {
        if(n==0) return 0;
        if(n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2*n+1,-1));
        return 1+f(1,n,1,dp);
    }
};