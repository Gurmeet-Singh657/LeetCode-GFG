//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& M,vector<vector<int>>& dp)
    {
        if(j==m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        // Right
        int Right=f(i,j+1,n,m,M,dp);
        // Right Down
        int RightDown=-1e9;
        if(i+1<n) RightDown=f(i+1,j+1,n,m,M,dp);
        int RightUp=-1e9;
        if(i-1>=0) RightUp=f(i-1,j+1,n,m,M,dp);
        return dp[i][j]=M[i][j]+max(Right,max(RightDown,RightUp));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi=-1e9;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,f(i,0,n,m,M,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends