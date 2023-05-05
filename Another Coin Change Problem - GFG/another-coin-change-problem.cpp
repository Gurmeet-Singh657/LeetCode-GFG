//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool f(int ind,int K,int target,vector<int>& coins,vector<vector<vector<int>>>& dp)
    {
        if(K==0) return target==0;
        if(dp[ind][K][target]!=-1) return dp[ind][K][target];
        if(ind==0)
        {
            if(target%coins[0]==0 && target/coins[0]==K) return true;
            return false;
        }
        bool nottake=f(ind-1,K,target,coins,dp);
        bool take=false;
        if(coins[ind]<=target)
            take=f(ind,K-1,target-coins[ind],coins,dp);
        return dp[ind][K][target]=take | nottake;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return f(N-1,K,target,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends