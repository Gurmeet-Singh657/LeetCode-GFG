//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int f(int ind,int cost[],int N,int W,vector<vector<int>>& dp)
	{
	    if(ind==N)
	    {
	        if(W==0) return 0;
	        return 1e9;
	    }
	    
	    if(dp[ind][W]!=-1) return dp[ind][W];
	    
	    int nottake=f(ind+1,cost,N,W,dp);
	    int take=1e9;
	    if(W>=ind+1 && cost[ind]!=-1)
	        take=cost[ind]+f(ind,cost,N,W-ind-1,dp);
	     return dp[ind][W]=min(take,nottake);
	}
	int minimumCost(int cost[], int N, int Weight) 
	{ 
	    vector<vector<int>> dp(N+1,vector<int>(Weight+1,1e9));
	    for(int i=0;i<=N;i++) dp[i][0]=0;
	    for(int W=0;W<=Weight;W++)
	    {
	        for(int ind=N-1;ind>=0;ind--)
	        {
	            int nottake=dp[ind+1][W];
	            int take=1e9;
	            if(W>=ind+1 && cost[ind]!=-1)
	                take=cost[ind]+dp[ind][W-ind-1];
	            dp[ind][W]=min(take,nottake);
	        }
	    }
        int ans=dp[0][Weight];
        if(ans>=1e9) return -1;
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends