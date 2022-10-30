//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    if(n==1) return 1;
	    vector<long long int> dp(n+1,-1);
	    dp[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        long long int prevsum=0;
	        int j=i-1;
	        while(j>=1 && j>=i-5)
	        {
	            prevsum+=dp[j];
	            j--;
	        }
	        dp[i]=prevsum*2;
	       // cout<<prevsum*2<<endl;
	    }
	   int j=n-1;
	   long long int prevsum=0;
	   while(j>=1 && j>=n-5)
	   {
	       prevsum+=dp[j];
	       j--;
	   }
	   //for(int i=1;i<=n;i++)
	   //cout<<dp[i]<<" ";
	    return dp[n]+prevsum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends