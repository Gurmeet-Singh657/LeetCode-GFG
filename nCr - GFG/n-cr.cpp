//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define mod (int)(1e9+7)
    #define ll long long int
    ll f(int n,int r,vector<vector<ll>>& dp)
    {
        if(n<r) return 0;
        if(dp[n][r]!=-1) return dp[n][r];
        if(r==0 || r==n) return 1;
        return dp[n][r]=(f(n-1,r-1,dp)+f(n-1,r,dp))%mod;
    }
    int nCr(int n, int r){
        vector<vector<ll>> dp(n+1,vector<ll>(r+1,-1));
        return f(n,r,dp);
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