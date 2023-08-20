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
        
        int Right=-1e9,UpRight=-1e9,DownRight=-1e9;
        Right=f(i,j+1,n,m,M,dp);
        if(i>0)
            UpRight=f(i-1,j+1,n,m,M,dp);
        if(i+1<n)
            DownRight=f(i+1,j+1,n,m,M,dp);
        return dp[i][j]=M[i][j]+max(Right,max(UpRight,DownRight));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int MaxGold=-1e9;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int row=0;row<n;row++)
        {
            int currGold=f(row,0,n,m,M,dp);
            MaxGold=max(MaxGold,currGold);
        }
        return MaxGold;
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