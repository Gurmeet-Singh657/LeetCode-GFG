//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    // lets say I have 
    // 1011001
    
    // 0 1 2 3 4 5 6
    // 1 0 1 1 0 0 1
    
    // if s[0]==1
    // for getting smaller -> 6 positions are available
    // so 6C4 available
    // 12 possible
    
    // if s[2]==1
    // for getting smaller -> 4 positions are available
    // so 4C3
    // 1001101 - 1001011 - 1001110 - 1000111
    
    // if S[3]==1
    // 3 positions are available
    //so 3C2
    // 1010101 - 1010011 - 1010110
    
    // if(S[6]==1)
    // 0 positions are available
    // finish
    long long ncr(int n, int r)
    {
        if(n<r)return 0;
        if (r > n - r)
            r = n - r;
        long long dp[r + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; 
        for (int i = 1; i <= n; i++) {
            for (int j = min(i, r); j > 0; j--)
                dp[j] = (dp[j] + dp[j - 1]);
        }
        return dp[r];
    }
    long long count(long long x) {
        long long count=0;
        vector<long long> ans;
        long long curr=x;
        while(curr>0)
        {
            if(curr&1)
            {
                ans.push_back(1);
                count++;
            }
            else
            {
                ans.push_back(0);
            }
            curr=curr>>1;
        }
        reverse(ans.begin(),ans.end());
        long long myans=0;
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1)
            {
                myans+=ncr(n-i-1,count);
                count--;
            }
        }
        return myans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends