//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n+1,1);
        vector<int> parent(n+1);
        int maxIndex=0,maxi=1;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    if(dp[i]<1+dp[j])
                    {
                        dp[i]=1+dp[j];
                        parent[i]=j;
                    }
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                maxIndex=i;
            }
        }
        vector<int> ans;
        int curr=maxIndex;
        while(curr!=parent[curr])
        {
            ans.push_back(arr[curr]);
            curr=parent[curr];
        }
        ans.push_back(arr[curr]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends