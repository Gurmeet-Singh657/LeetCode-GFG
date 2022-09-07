class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,0));
        vector<int> prefixsum(stones.size(),0);
        prefixsum[0]=stones[0];
        for(int i=1;i<stones.size();i++)
            prefixsum[i]=prefixsum[i-1]+stones[i];
        for(int i=stones.size()-1;i>=0;i--)
        {
            for(int j=i+1;j<stones.size();j++)
            {
                dp[i][j]=max(prefixsum[j]-prefixsum[i]-dp[i+1][j],prefixsum[j-1]-(i == 0 ? 0 : prefixsum[i-1])-dp[i][j-1]);
            }
        }
        return dp[0][stones.size()-1];
    }
};