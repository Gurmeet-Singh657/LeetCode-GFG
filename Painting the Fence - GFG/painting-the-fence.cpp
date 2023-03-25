//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define mod (int)(1e9+7)
    long long f(int n,int k,vector<long long>& dp)
    {
        if(n==0) return 1;
        if(k==0) return 0;
        if(dp[n]!=-1) return dp[n];
        long long ones=k*1LL*f(n-1,k,dp);
        long long twos=0;
        if(n>=2)
        twos=k*1LL*f(n-2,k,dp);
        return dp[n]=(ones+twos)%mod;
    }
    long long countWays(int n, int k){
        long long ans=0;
        vector<long long> dp(n+1,0);
        if(k==1) 
        {
            if(n<=2) return 1;
            return 0;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            long long ones=(k-1)*1LL*dp[i-1];
            long long twos=0;
            if(i>=2)
                twos=(k-1)*1LL*dp[i-2];
            dp[i]=(ones+twos)%mod;
        }
        ans+=k*1LL*dp[n-1];
        if(n>=2)
        ans=(ans+k*1LL*dp[n-2])%mod;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends