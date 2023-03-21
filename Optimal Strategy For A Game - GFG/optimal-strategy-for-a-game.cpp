//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long f(int i,int j,int arr[],vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int first=arr[i]+min(f(i+1,j-1,arr,dp),f(i+2,j,arr,dp));
        int second=arr[j]+min(f(i+1,j-1,arr,dp),f(i,j-2,arr,dp));
        return dp[i][j]=max(first,second);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                int first=arr[i]+min((i+1<n && j-1>=0?dp[i+1][j-1]:1e9),(i+2<n?dp[i+2][j]:1e9));
                int second=arr[j]+min((i+1<n && j-1>=0?dp[i+1][j-1]:1e9),(j-2>=0?dp[i][j-2]:1e9));
                dp[i][j]=max(first,second);
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends