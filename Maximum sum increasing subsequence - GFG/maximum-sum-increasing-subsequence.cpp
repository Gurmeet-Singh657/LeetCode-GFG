//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int ind,int prev,int arr[],int n,vector<vector<int>>& dp)
	{
	    if(ind==n) return 0;
	    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
	    int nottake=f(ind+1,prev,arr,n,dp);
	    int take=-1e9;
	    if(prev==-1 || arr[ind]>arr[prev])
	        take=arr[ind]+f(ind+1,ind,arr,n,dp);
	    return dp[ind][prev+1]=max(take,nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return f(0,-1,arr,n,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends