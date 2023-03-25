//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int f(int i,int j,int k,string& A,string& B,string& C,int n1,int n2,int n3,vector<vector<vector<int>>>& dp)
{
    if(i==n1 || j==n2 || k==n3) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int ans=0;
    if(A[i]==B[j] && B[j]==C[k])
        ans=1+f(i+1,j+1,k+1,A,B,C,n1,n2,n3,dp);
    else
    {
        ans=max(ans,f(i+1,j,k,A,B,C,n1,n2,n3,dp));
        ans=max(ans,f(i,j+1,k,A,B,C,n1,n2,n3,dp));
        ans=max(ans,f(i,j,k+1,A,B,C,n1,n2,n3,dp));
    }
    return dp[i][j][k]=ans;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            for(int k=n3-1;k>=0;k--)
            {
                int ans=0;
                if(A[i]==B[j] && B[j]==C[k])
                    ans=1+dp[i+1][j+1][k+1];
                else
                {
                    ans=max(ans,dp[i+1][j][k]);
                    ans=max(ans,dp[i][j+1][k]);
                    ans=max(ans,dp[i][j][k+1]);
                }
                dp[i][j][k]=ans;
            }
        }
    }
    return dp[0][0][0];
}