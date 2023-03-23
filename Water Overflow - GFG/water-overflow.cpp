//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        vector<vector<double>> dp(102,vector<double>(102,0.0));
        dp[1][1]=(double)K;
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=i;j++)
            {
                double curr=(dp[i][j]-1.0)/2.0;
                if(curr>0.0)
                {
                    dp[i+1][j]+=curr;
                    dp[i+1][j+1]+=curr;
                }
            }
        }
        return min(1.0,dp[R][C]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
// } Driver Code Ends