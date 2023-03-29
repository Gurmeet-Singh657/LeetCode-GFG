//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int ind,int target,int N,int arr[],vector<vector<int>>& dp)
    {
        if(ind==N)
            return target==0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake=f(ind+1,target,N,arr,dp);
        bool take=false;
        if(target>=arr[ind]) take=f(ind+1,target-arr[ind],N,arr,dp);
        return dp[ind][target]=take || nottake;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        vector<vector<int>> dp(N+1,vector<int>(sum/2+1,-1));
        return f(0,sum/2,N,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends