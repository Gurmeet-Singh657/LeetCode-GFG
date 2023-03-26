//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind,int prev,int N,int A[],vector<vector<int>>& dp)
    {
        if(ind==N) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nottake=f(ind+1,prev,N,A,dp);
        int take=-1e9;
        if(prev==-1 || abs(A[ind]-A[prev])==1)
            take=1+f(ind+1,ind,N,A,dp);
        return dp[ind][prev+1]=max(take,nottake);
    }
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>> dp(N+2,vector<int>(N+1,-1));
        return f(0,-1,N,A,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends