//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    #define MOD (int)(1e9+7)
    long long solve(int ind,int n,vector<int>& dp)
    {
        if(ind==n) return 1;
        if(ind>n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long oneStep=solve(ind+1,n,dp);
        long long twoStep=solve(ind+2,n,dp);
        long long threeStep=solve(ind+3,n,dp);
        return dp[ind]=(oneStep+0LL+twoStep+threeStep)%MOD;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends