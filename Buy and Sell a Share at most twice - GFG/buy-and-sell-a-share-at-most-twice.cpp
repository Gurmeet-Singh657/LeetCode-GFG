//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int f(int ind,int num,int n,vector<int>& price,vector<vector<int>>& dp)
{
    if(ind==n) return 0;
    if(num==4) return 0;
    if(dp[ind][num]!=-1) return dp[ind][num];
    int nottake=f(ind+1,num,n,price,dp);
    int take=-1e9;
    if(num%2==0) // buy
    {
        take=-price[ind]+f(ind+1,num+1,n,price,dp);
    }
    else // sell
    {
        take=price[ind]+f(ind+1,num+1,n,price,dp);
    }
    return dp[ind][num]=max(take,nottake);
}
int maxProfit(vector<int>&price){
    int n=price.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return f(0,0,n,price,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends