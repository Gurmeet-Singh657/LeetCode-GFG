//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int f(int i,int j,string& A,string& B,vector<vector<int>>& dp)
    {
        if(i==A.length() || j==B.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(A[i]==B[j])
        {
            ans=1+f(i+1,j+1,A,B,dp);
        }
        else
        {
            ans=max(f(i+1,j,A,B,dp),f(i,j+1,A,B,dp));
        }
        return dp[i][j]=ans;
    }
    int longestPalinSubseq(string A) {
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,A,B,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends