//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>> dp(N+2,vector<int>(N+2,-0));
        for(int ind=N-1;ind>=0;ind--)
        {
            for(int prev=-1;prev<ind;prev++)
            {
                int nottake=dp[ind+1][prev+1];
                int take=-1e9;
                if(prev==-1 || abs(A[ind]-A[prev])==1)
                    take=1+dp[ind+1][ind+1];
                dp[ind][prev+1]=max(take,nottake);
            }
        }
        return dp[0][0];
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