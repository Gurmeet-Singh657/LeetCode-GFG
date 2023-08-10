//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int f(int i,int j,string& s1,string& s2,int n,int m,vector<vector<int>>& dp)
    {
        if(i==n || j==m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans;
        if(s1[i]==s2[j])
        {
            ans=1+f(i+1,j+1,s1,s2,n,m,dp);
        }
        else
        {
            ans=max(f(i,j+1,s1,s2,n,m,dp),f(i+1,j,s1,s2,n,m,dp));
        }
        return dp[i][j]=ans;
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,s1,s2,n,m,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends