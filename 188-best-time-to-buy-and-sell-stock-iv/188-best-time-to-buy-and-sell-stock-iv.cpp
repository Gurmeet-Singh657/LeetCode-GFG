class Solution {
public:
    int f(int ind,vector<int>& prices,int k,int buy,vector<vector<vector<int>>>& dp)
    {
        if(k==0) return 0;
        if(ind==prices.size())
            return 0;
        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];
        if(buy==1)
            return dp[ind][k][buy]=max(-prices[ind]+f(ind+1,prices,k,0,dp),f(ind+1,prices,k,1,dp));
        else
            return dp[ind][k][buy]=max(prices[ind]+f(ind+1,prices,k-1,1,dp),f(ind+1,prices,k,0,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return f(0,prices,k,1,dp);
    }
};