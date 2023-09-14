//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 	public:
    #define MOD (int)(1e9+7)
	int solve(int ind,int arr[],int n,int sum,vector<vector<int>>& dp)
	{
	    if(ind==n) return sum==0;
	    if(sum<0) return 0;
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int take=solve(ind+1,arr,n,sum-arr[ind],dp);
	    int notTake=solve(ind+1,arr,n,sum,dp);
	    return dp[ind][sum]=(take+notTake)%MOD;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends