class Solution {
public:
    int dx[8]={-2,-2,2,2,-1,-1,1,1};
    int dy[8]={-1,1,-1,1,-2,2,-2,2};
    double f(int i,int j,int n,int k,vector<vector<vector<double>>>& dp)
    {
        if(k==0)
            return 1.0;
        double ans=0.0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        for(int ind=0;ind<8;ind++)
        {
            int row=dx[ind]+i;
            int col=dy[ind]+j;
            if(row>=0 && row<n && col>=0 && col<n)
            {
                ans+=(0.125*f(row,col,n,k-1,dp));
            }
        }
        return dp[i][j][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return f(row,column,n,k,dp);
    }
};