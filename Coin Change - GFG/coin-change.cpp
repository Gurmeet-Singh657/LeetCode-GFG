//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int ind,int coins[],int N,int sum,vector<vector<long long int>>& dp)
    {
        if(ind==N) return sum==0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        long long int nottake=f(ind+1,coins,N,sum,dp);
        long long int take=0;
        if(sum>=coins[ind])
        {
            take=f(ind,coins,N,sum-coins[ind],dp);
        }
        return dp[ind][sum]=take+nottake;
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        sort(coins,coins+N);
        return f(0,coins,N,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends