class Solution {
public:
    int f(vector<int>& nums,vector<int>& multipliers,int ind,int start,vector<vector<int>>& dp,int m,int n)
    {
        if(ind==m)
            return 0;
        if(dp[ind][start]!=INT_MIN) return dp[ind][start];
        int end=n-1-(ind-start);
        int takest=(nums[start]*multipliers[ind])+f(nums,multipliers,ind+1,start+1,dp,m,n);
        int takeend=(nums[end]*multipliers[ind])+f(nums,multipliers,ind+1,start,dp,m,n);
        return dp[ind][start]=max(takest,takeend);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        int n=nums.size();
        vector<vector<int>> dp(1000,vector<int>(1000,INT_MIN));
//         for(int i=0;i<=n;i++)
//             dp[m][i]=0;
//         for(int ind=n-1;ind>=0;ind--)
//         {
//             for(int start=0;start<=ind;start++)
//             {
//                 int end=n-1-(ind-start);
//                 int takest=(nums[start]*multipliers[ind])+dp[ind+1][start+1];
//                 int takeend=(nums[end]*multipliers[ind])+dp[ind+1][start];
//                 dp[ind][start]=max(takest,takeend);
                
//             }
//         }
        // return dp[0][0];
        return f(nums,multipliers,0,0,dp,m,n);
    }
};