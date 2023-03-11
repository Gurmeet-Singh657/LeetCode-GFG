class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& dp)
    {
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=f(i+1,j,n,m,dp);
        int right=f(i,j+1,n,m,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) continue;
                int down=dp[i+1][j];
                int right=dp[i][j+1];
                dp[i][j]=down+right;
            }
        }
        return dp[0][0];
    }
};