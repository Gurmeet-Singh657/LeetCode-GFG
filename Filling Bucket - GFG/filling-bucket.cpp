//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  #define mod (int)(1e8)
  public:
    long long f(int N,vector<int>& dp)
    {
        if(N<0)
        return 0;
        if(N==0)
        return 1;
        if(dp[N]!=-1) return dp[N];
        return dp[N]=(f(N-1,dp)%mod+f(N-2,dp)%mod)%mod;
    }
    int fillingBucket(int N) {
        vector<int> dp(N+1,-1);
        return f(N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends