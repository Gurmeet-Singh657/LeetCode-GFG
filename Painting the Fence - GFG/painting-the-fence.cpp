//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define MOD (int)(1e9+7)
    long long countWays(int n, int k){
        if(k==1) return n<=2;
        vector<int> dp(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            long long ans=0;
            ans=(ans+((k-1)*1LL*dp[i-1])%MOD)%MOD;
            if(n>=2)
            ans=(ans+((k-1)*1LL*dp[i-2])%MOD)%MOD;
            dp[i]=ans;
        }
        long long ans=0;
        ans=(ans+(k*1LL*dp[n-1])%MOD)%MOD;
        ans=(ans+(k*1LL*dp[n-2])%MOD)%MOD;
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