//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind,int W,int val[],int wt[],int N,vector<vector<int>>& dp)
    {
        if(ind==N) return 0;
        if(dp[ind][W]!=-1) return dp[ind][W];
        int nottake=f(ind+1,W,val,wt,N,dp);
        int take=-1e9;
        if(wt[ind]<=W)
            take=val[ind]+f(ind,W-wt[ind],val,wt,N,dp);
        return dp[ind][W]=max(take,nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return f(0,W,val,wt,N,dp);
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