//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int ind,int W,int wt[],int val[],int n,vector<vector<int>>& dp)
    {
        if(ind==n) return 0;
        if(dp[ind][W]!=-1) return dp[ind][W];
        int nottake=f(ind+1,W,wt,val,n,dp);
        int take=-1e9;
        if(wt[ind]<=W) take=val[ind]+f(ind+1,W-wt[ind],wt,val,n,dp);
        return dp[ind][W]=max(take,nottake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        return f(0,W,wt,val,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends