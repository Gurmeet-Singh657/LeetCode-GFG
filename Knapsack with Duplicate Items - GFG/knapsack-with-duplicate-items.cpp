//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int val[],int wt[],int N,int W,vector<vector<int>>& dp)
    {
        if(ind==N) return 0;
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        int notTake=solve(ind+1,val,wt,N,W,dp);
        int take=-1e9;
        if(wt[ind]<=W)
        {
            take=val[ind]+solve(ind,val,wt,N,W-wt[ind],dp);
        }
        return dp[ind][W]=max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solve(0,val,wt,N,W,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends