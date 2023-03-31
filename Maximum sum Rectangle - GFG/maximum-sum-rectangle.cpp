//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<vector<int>> presum(R,vector<int>(C,0));
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                presum[i][j]+=M[i][j];
                if(i>0) presum[i][j]+=presum[i-1][j];
            }
        }
        int maxsum=-1e9;
        for(int curri=0;curri<R;curri++)
        {
            for(int previ=0;previ<=curri;previ++)
            {
                int currsum=0;
                for(int j=0;j<C;j++)
                {
                    int diff=presum[curri][j]-(previ>0?presum[previ-1][j]:0);
                    currsum+=diff;
                    maxsum=max(maxsum,currsum);
                    if(currsum<0) currsum=0;
                }
            }
            
        }
        return maxsum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends