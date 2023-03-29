//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int n=nums.size();
		    vector<vector<int>> dp(n,vector<int>(2,0));
		    dp[0][0]=dp[0][1]=1;
		    for(int i=1;i<n;i++)
		    {
		            if(nums[i]>nums[i-1])
		            {
		                dp[i][1]=1+dp[i-1][0]; // Take previous dec and add this to answer
		                dp[i][0]=dp[i-1][0]; // pass this dec ahead so that it can be used
		            }
		            if(nums[i]<nums[i-1])
		            {
		                dp[i][0]=1+dp[i-1][1]; // Take previous inc and add this to answer
		                dp[i][1]=dp[i-1][1]; // pass this inc ahead so that it can be used
		            }
		            if(nums[i]==nums[i-1])
		            {
		                dp[i][0]=dp[i-1][0];
		                dp[i][1]=dp[i-1][1];
		            }
		    }
		    return max(dp[n-1][0],dp[n-1][1]);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends