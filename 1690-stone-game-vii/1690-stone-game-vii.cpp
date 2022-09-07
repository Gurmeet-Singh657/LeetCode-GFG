class Solution {
public:
    int f(int i,int j,vector<int>& stones,int sum,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(sum-stones[i]-f(i+1,j,stones,sum-stones[i],dp),sum-stones[j]-f(i,j-1,stones,sum-stones[j],dp));
    }
    int stoneGameVII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        return f(0,stones.size()-1,stones,sum,dp);
    }
};