//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Memoisation
    // #define mod (int)(1e9+7)
    // int f(int n,int r,vector<vector<int>>& dp)
    // {
    //     if(n<r) return 0;
    //     if(r==0 || n==r) return 1;
    //     if(dp[n][r]!=-1) return dp[n][r];
    //     return dp[n][r]=(f(n-1,r-1,dp)+0LL+f(n-1,r,dp))%mod;
    // }
    // int nCr(int n, int r){
    //     vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
    //     return f(n,r,dp);
    // }
    // Tabulation
    #define mod (int)(1e9+7)
    int f(int n,int r,vector<vector<int>>& dp)
    {
        if(n<r) return 0;
        if(r==0 || n==r) return 1;
        if(dp[n][r]!=-1) return dp[n][r];
        return dp[n][r]=(f(n-1,r-1,dp)+0LL+f(n-1,r,dp))%mod;
    }
    int nCr(int n, int r){
        if(n<r) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=(dp[i-1][j-1]+0LL+dp[i-1][j])%mod;
            }
        }
        return dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends