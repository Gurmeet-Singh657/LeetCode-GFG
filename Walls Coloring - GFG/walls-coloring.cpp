//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int f(int ind,int prev,vector<vector<int>>& colors,int N,vector<vector<int>>& dp)
    {
        if(ind==N) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int ans=1e9;
        if(prev!=1)
        {
            int take0=colors[ind][0]+f(ind+1,1,colors,N,dp);
            ans=min(ans,take0);
        }
        if(prev!=2)
        {
            int take1=colors[ind][1]+f(ind+1,2,colors,N,dp);
            ans=min(ans,take1);
        }
        if(prev!=3)
        {
            int take2=colors[ind][2]+f(ind+1,3,colors,N,dp);
            ans=min(ans,take2);
        }
        return dp[ind][prev]=ans;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        vector<vector<int>> dp(N,vector<int>(4,-1));
        return f(0,0,colors,N,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends