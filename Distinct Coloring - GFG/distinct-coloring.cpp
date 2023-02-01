//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    long long int mincost(int i, int r[], int g[], int b[], int N, int color,
    vector<vector<long long int>>&dp){
        if(i == N) return 0;
        
        if(dp[i][color] != -1) return dp[i][color];
        
        long long int paint1 = 1e11, paint2 = 1e11, paint3 = 1e11;
        if(color != 1)
            paint1 = r[i] + mincost(i+1, r, g, b, N, 1, dp);
        if(color != 2)
            paint2 = g[i] + mincost(i+1, r, g, b, N, 2, dp);
        if(color != 3)
            paint3 = b[i] + mincost(i+1, r, g, b, N, 3, dp);
        
        return dp[i][color] = min(paint1,min(paint2, paint3));
        
    }
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>> dp(N, vector<long long int>(4, -1));
        return mincost(0,r,g,b,N, 0, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends