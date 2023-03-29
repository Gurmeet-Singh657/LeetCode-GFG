//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        for(int weight=0;weight<=W;weight++)
        {
            for(int ind=N-1;ind>=0;ind--)
            {
                int nottake=dp[ind+1][weight];
                int take=-1e9;
                if(wt[ind]<=weight)
                    take=val[ind]+dp[ind][weight-wt[ind]];
                dp[ind][weight]=max(take,nottake);
            }
        }
        return dp[0][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends