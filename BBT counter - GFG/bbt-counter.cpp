//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    #define mod (int)(1e9+7)
    long long int countBT(int h) { 
        vector<long long int> dp(h+1,0);
        dp[1]=1,dp[2]=3;
        for(int i=3;i<=h;i++)
        {
            // i-1 height left and i-2 height right
            dp[i]=(dp[i] + (dp[i-1]*dp[i-2])%mod)%mod;
            // i-1 height left and i-1 height right
            dp[i]=(dp[i] + (dp[i-1]*dp[i-1])%mod)%mod;
            // i-2 height left and i-1 height right
            dp[i]=(dp[i] + (dp[i-2]*dp[i-1])%mod)%mod;
        }
        return dp[h];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends