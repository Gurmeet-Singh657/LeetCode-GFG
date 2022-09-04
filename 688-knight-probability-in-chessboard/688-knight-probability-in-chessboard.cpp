class Solution {
public:
    int dx[8]={-2,-2,2,2,-1,-1,1,1};
    int dy[8]={-1,1,-1,1,-2,2,-2,2};
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n+1,vector<double>(n+1,0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[0][i][j]=1.0;
            }
        }
        for(int ki=1;ki<=k;ki++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    double ans=0.0;
                    for(int ind=0;ind<8;ind++)
                    {
                        int crow=dx[ind]+i;
                        int ccol=dy[ind]+j;
                        if(crow>=0 && crow<n && ccol>=0 && ccol<n)
                        {
                            ans+=(0.125*dp[ki-1][crow][ccol]);
                        }
                    }
                    dp[ki][i][j]=ans;
                }
            }
        }
        return dp[k][row][column];
    }
};