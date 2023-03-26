//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int N,vector<vector<int>>& Matrix,vector<vector<int>>& dp)
    {
        if(i==N) return 0;
        int maxi=-1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=-1;k<=1;k++)
        {
            int col=k+j;
            if(col>=0 && col<N)
                maxi=max(maxi,f(i+1,col,N,Matrix,dp));
        }
        return dp[i][j]=Matrix[i][j]+maxi;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxsum=-1e9;
        vector<vector<int>> dp(N,vector<int>(N,-1));
        for(int j=0;j<N;j++)
        {
            maxsum=max(maxsum,f(0,j,N,Matrix,dp));
        }
        return maxsum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends