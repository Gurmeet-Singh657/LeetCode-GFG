//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int f(int ind,int k,vector<int>& nums,vector<int>& dp)
    {
        if(ind==nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mini=1e9;
        int total=0;
        for(int i=ind;i<nums.size();i++)
        {
            total+=nums[i];
            if(total<=k)
            {
                int curr=f(i+1,k,nums,dp);
                if(i+1!=nums.size()) curr+=(k-total)*(k-total);
                mini=min(mini,curr);
            }
            else
                break;
            total+=1;
        }
        return dp[ind]=mini;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,k,nums,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends