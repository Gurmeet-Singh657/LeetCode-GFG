//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long int f(int i,vector<int> adj[],int N,vector<vector<long long int>>& dp)
	{
	    if(N==0) return 1;
	    if(dp[i][N]!=-1) return dp[i][N];
	    long long int ways=0;
	    for(auto it:adj[i])
	    {
	        ways+=f(it,adj,N-1,dp);
	    }
	    return dp[i][N]=ways;
	}
	long long getCount(int N)
	{
		vector<int> adj[10]={
		    {0,8},
		    {1,2,4},
		    {1,2,5,3},
		    {2,3,6},
		    {1,4,5,7},
		    {2,4,5,6,8},
		    {3,5,6,9},
		    {4,7,8},
		    {0,5,7,8,9},
		    {6,8,9}};
	     long long int ways=0;
	     vector<vector<long long int>> dp(10,vector<long long int>(N+1,-1));
	     for(int i=0;i<=9;i++)
	     {
	         ways+=f(i,adj,N-1,dp);
	     }
	     return ways;
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends