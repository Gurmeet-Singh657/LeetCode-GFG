class Solution {
public:
    int dx[8]={-2,-2,2,2,-1,-1,1,1};
    int dy[8]={-1,1,-1,1,-2,2,-2,2};
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n+1,vector<double>(n+1,0)),prev(n+1,vector<double>(n+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                prev[i][j]=1.0;
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
                            ans+=(0.125*prev[crow][ccol]);
                        }
                    }
                    curr[i][j]=ans;
                }
            }
            prev=curr;
        }
        return prev[row][column];
    }
};