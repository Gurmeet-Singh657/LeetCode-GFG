//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    #define mod (int)(1e9+7)
    int f(int n,vector<int>& dp)
    {
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=(f(n-1,dp)+(n-1)*1LL*f(n-2,dp))%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends