//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int ind,int trans,int K,int N,int A[],vector<vector<int>>& dp)
    {
        if(trans==K || ind==N) return 0;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        int nottake=f(ind+1,trans,K,N,A,dp);
        int take=-1e9;
        if(trans%2==0)
            take=-A[ind]+f(ind+1,trans+1,K,N,A,dp);
        else 
            take=A[ind]+f(ind+1,trans+1,K,N,A,dp);
        return dp[ind][trans]=max(take,nottake);
    } 
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>> dp(N,vector<int>(2*K+1,-1));
        return f(0,0,2*K,N,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends